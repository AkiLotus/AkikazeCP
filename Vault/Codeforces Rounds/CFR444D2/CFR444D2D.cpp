/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

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

/** -----IDEAS/ALGORITHMS----- **/


/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 n, a, b, c, d, start, len;
i64 first = -1, last = -1;
vector<i64> t, q;
vector<i64> rating;
vector<i64> tseChange;
i64 tree[5555555];

/** -----EXTENSIVE FUNCTIONS----- **/
void ITBuild (i64 node, i64 left, i64 right) {
	if (left > right) return;
	if (left == right) {
		tree[node] = left;
		return;
	}
	ITBuild(node*2, left, (left+right)/2);
	ITBuild(node*2+1, (left+right)/2+1, right);
	if (tseChange[tree[node*2]] < tseChange[tree[node*2+1]]) tree[node] = tree[node*2];
	else tree[node] = tree[node*2+1];
}

i64 ITget(i64 node, i64 left, i64 right, i64 st, i64 en) {
	if (left > right || right < st || en < left) return -1;
	if (left <= st && right <= en) return tree[node];
	i64 p1 = ITget(node*2, left, (left+right)/2, st, en);
	i64 p2 = ITget(node*2+1, 1+(left+right)/2, right, st, en);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	if (tseChange[p1] < tseChange[p2]) return p1;
	return p2;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n >> a >> b >> c >> d >> start >> len;
	t.resize(n); q.resize(n);
	rating.resize(n, 0);
	tseChange.resize(n, 0);
	for (i64 i=0; i<n; i++) {
		cin >> t[i] >> q[i];
		if (q[i] == 0) {
			if (i == 0) {
				rating[i] = start - b;
				tseChange[i] = -d;
			}
			else {
				rating[i] = rating[i-1] - b;
				tseChange[i] = tseChange[i-1] - d;
			}
		}
		else if (i == 0) {
			rating[i] = start + a;
			tseChange[i] = c;
		}
		else {
			rating[i] = rating[i-1] + a;
			tseChange[i] = tseChange[i-1] + c;
		}
		if (rating[i] < 0) {
			if (first == -1) first = i;
			last = i;
		}
		//cout << tseChange[i] << " ";
	}
	//cout << endl;
	ITBuild(1, 0, n-1);
}

void ProSolve() {
	if (first == last && first == -1) {
		i64 pos = upper_bound(t.begin(), t.end(), len+1) - t.begin() - 1;
		if (pos == -1) {
			cout << "1"; return;
		}
		//cout << pos << endl;
		i64 minimum = ITget(1, 0, n-1, 0, pos);
		//cout << minimum << endl;
		if (start + tseChange[minimum] >= 0) {
			cout << "1"; return;
		}
		for (int i=0; i<n; i++) {
			i64 pos = upper_bound(t.begin(), t.end(), len+1) - t.begin() - 1;
			i64 minimum = ITget(1, 0, n-1, i, pos);
			if ((i > 0 && rating[i-1] + tseChange[minimum] - tseChange[i-1] >= 0) || (i == 0 && start + tseChange[minimum] >= 0)) {
				cout << t[i]; return;
			}
		}
		cout << t[n-1]+1; return;
	}
	i64 st = lower_bound(t.begin(), t.end(), t[last]-len) - t.begin();
	i64 en = last;
	if (st > first) {
		cout << "-1"; return;
	}
	i64 minimum = ITget(1, 0, n-1, st, en);
	if ((st > 0 && rating[st-1] + tseChange[minimum] - tseChange[st-1] >= 0) || (st == 0 && start + tseChange[minimum] >= 0)) {
		cout << t[st]; return;
	}
	cout << "-1"; return;
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
