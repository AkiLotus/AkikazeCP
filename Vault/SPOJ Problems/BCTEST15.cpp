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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here


// global variables here
int m, n;
int board[111][111];

// functions here

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	cin >> m >> n;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			cin >> board[i][j];
			int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
			if (i > 1 && j > 2) tmp1 = board[i][j] + board[i-1][j-2];
			if (i > 2 && j > 1) tmp2 = board[i][j] + board[i-2][j-1];
			if (i > 1 && j <= n-2) tmp3 = board[i][j] + board[i-1][j+2];
			if (i > 2 && j <= n-1) tmp4 = board[i][j] + board[i-2][j+1];
			board[i][j] = max(board[i][j], max(max(tmp1, tmp2), max(tmp3, tmp4)));
		}
	}
	cout << *max_element(board[m]+1, board[m]+n+1);
	return 0;
}
