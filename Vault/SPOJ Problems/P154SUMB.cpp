// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
int T, cas = 0; // for multi-testcase problems
i64 N, ans = 0, siz; vector<i64> a;
map<i64, i64> M;
vector<i64> distinctValue;
vector<i64> leafPos;
i64 sumTree[666666];

/** -----EXTENSIVE FUNCTIONS----- **/
void ITBuild(i64 node, i64 st, i64 en) {
	if (st > en) return;
	if (st == en) {
		leafPos[st] = node;
		return;
	}
	ITBuild(node*2, st, (st+en)/2);
	ITBuild(node*2+1, (st+en)/2+1, en);
}

void ITUpdate(i64 z) {
	i64 node = leafPos[z];
	while (node > 0) {
		sumTree[node]++; node /= 2;
	}
}

i64 ITGet(i64 node, i64 left, i64 right, i64 st, i64 en) {
	if (left > right) return 0;
	if (right < st || en < left) return 0;
	if (st <= left && right <= en) return sumTree[node];
	i64 p1 = ITGet(node*2, left, (left+right)/2, st, en);
	i64 p2 = ITGet(node*2+1, (left+right)/2+1, right, st, en);
	return (p1 + p2);
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> N; a.resize(N, 0);
	for (i64 i=0; i<N; i++) {
		cin >> a[i]; M[a[i]]++;
		if (M[a[i]] == 1) {
			distinctValue.pub(a[i]);
		}
	}
	siz = distinctValue.size();
	sort(distinctValue.begin(), distinctValue.end());
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	leafPos.resize(siz, 0);
	ITBuild(1, 0, siz-1);
	for (i64 i=N-1; i>=0; i--) {
		i64 position = lower_bound(distinctValue.begin(), distinctValue.end(), a[i]) - distinctValue.begin();
		ITUpdate(position);
		ans += ITGet(1, 0, siz-1, 0, position-1);
	}
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
