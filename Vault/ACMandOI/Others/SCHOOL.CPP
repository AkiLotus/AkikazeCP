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

// custom typedef here


// global variables here


// functions here


/**
	Từ điểm 1, gắn nhãn cho toàn bộ các đỉnh của đồ thị bằng Dijkstra.
	Mảng tạo lập: L1[i] (đường đi ngắn nhất từ 1->i)
	Từ điểm k, gắn nhãn giật lùi.
	Mảng tạo lập: LK[i] (đường đi ngắn nhất từ i->k)
	Từ điểm n, gắn nhãn giật lùi.
	Mảng tạo lập: Ln[i] (đường đi ngắn nhất từ i->n)

	Tìm h thỏa mãn: L1[h] + LK[h] + Ln[h] đạt GTNN.

	Độ phức tạp: O(N^2) (thông thường) / O(NlogN+MlogM) (CTDL heap)
**/

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);

	return 0;
}
