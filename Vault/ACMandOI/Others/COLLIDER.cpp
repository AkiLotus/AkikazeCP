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

/** -----IDEAS/ALGORITHMS-----
	Sử dụng stack. Các phần tử trên stack là vị trí các hạt p+.
	Thực hiện push khi gặp p+, pop và lưu thời điểm xảy ra collision khi gặp e-.
	Sử dụng prefix sum để tính toán quy hoạch động.
    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 N, M;
map<i64, i64> Map;
stack<i64> posi;
vector<pii> colliData(1, mp(-1, 0));
vector<i64> prefixSum;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N;
	for (i64 i=0; i<N; i++) {
        i64 x, e; cin >> x >> e;
        if (e == 1) posi.push(x);
        else if (!posi.empty()) {
			i64 nearestPositron = posi.top(); posi.pop();
			i64 moment = (x - nearestPositron + 1) / 2;
			if (Map[moment] > 0) colliData[Map[moment]].se++;
			else {
				Map[moment] = colliData.size();
				colliData.pub(mp(moment, 1));
			}
        }
	}
	sort(colliData.begin(), colliData.end());
	prefixSum.resize(colliData.size(), 0);
	for (i64 i=1; i<prefixSum.size(); i++) prefixSum[i] = prefixSum[i-1] + colliData[i].se;
}

void ProSolve() {
	cin >> M;
	while (M--) {
		i64 T; cin >> T;
		pii mark = mp(T, LINF);
		i64 pos = upper_bound(colliData.begin(), colliData.end(), mark) - colliData.begin() - 1;
		if (pos == -1) cout << N << endl;
		else cout << N - 2 * prefixSum[pos] << endl;
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	freopen("COLLIDER.INP", "r", stdin);
	freopen("COLLIDER.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
