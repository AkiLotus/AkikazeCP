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


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	int n, m; cin >> n >> m;
	int curX = 0, curY = 0;
	bool swapLR = false, swapUD = false;
	char board[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) cin >> board[i][j];
	}
	if (board[0][1] != '*' && board[1][0] != '*') {
		cout << "D\n"; fflush(stdout);
		cin >> curX >> curY; curX--; curY--;
		if (curX == -2 && curY == -2) return 0;
		if (board[curX][curY] == 'F') return 0;
		if (curX == 0 && curY == 0) swapUD = true;
		else {
			cout << "U\n"; fflush(stdout);
			cin >> curX >> curY; curX--; curY--;
			if (curX == -2 && curY == -2) return 0;
			if (board[curX][curY] == 'F') return 0;
		}
		cout << "R\n"; fflush(stdout);
		cin >> curX >> curY; curX--; curY--;
		if (curX == -2 && curY == -2) return 0;
		if (board[curX][curY] == 'F') return 0;
		if (curX == 0 && curY == 0) swapLR = true;
		else {
			cout << "L\n"; fflush(stdout);
			cin >> curX >> curY; curX--; curY--;
			if (curX == -2 && curY == -2) return 0;
			if (board[curX][curY] == 'F') return 0;
		}
	}
	else if (board[1][0] != '*') {
		cout << "D\n"; fflush(stdout);
		cin >> curX >> curY; curX--; curY--;
		if (curX == -2 && curY == -2) return 0;
		if (board[curX][curY] == 'F') return 0;
		if (curX == 0 && curY == 0) {
			swapUD = true;
			cout << "U\n"; fflush(stdout);
			cin >> curX >> curY; curX--; curY--;
			if (curX == -2 && curY == -2) return 0;
			if (board[curX][curY] == 'F') return 0;
		}
		for (int i=1; i<n; i++) {
			if (board[i][1] == '*') {
				if (swapUD) cout << "U\n";  else cout << "D\n";
				fflush(stdout);
				cin >> curX >> curY; curX--; curY--;
				if (curX == -2 && curY == -2) return 0;
				if (board[curX][curY] == 'F') return 0;
				continue;
			}
			cout << "R\n"; fflush(stdout);
			cin >> curX >> curY; curX--; curY--;
			if (curX == -2 && curY == -2) return 0;
			if (board[curX][curY] == 'F') return 0;
			if (curY == 0) swapLR = true;
			else {
				cout << "L\n"; fflush(stdout);
				cin >> curX >> curY; curX--; curY--;
				if (curX == -2 && curY == -2) return 0;
				if (board[curX][curY] == 'F') return 0;
			}
			break;
		}
		int tmp = curX;
		for (int i=0; i<curX; i++) {
			if (swapUD) cout << "D\n";  else cout << "U\n";
			fflush(stdout);
			cin >> curX >> curY; curX--; curY--;
			if (curX == -2 && curY == -2) return 0;
			if (board[curX][curY] == 'F') return 0;
		}
	}
	else if (board[0][1] != '*') {
		cout << "R\n"; fflush(stdout);
		cin >> curX >> curY; curX--; curY--;
		if (curX == -2 && curY == -2) return 0;
		if (board[curX][curY] == 'F') return 0;
		if (curX == 0 && curY == 0) swapLR = true;
		else {
			cout << "L\n"; fflush(stdout);
			cin >> curX >> curY; curX--; curY--;
			if (curX == -2 && curY == -2) return 0;
			if (board[curX][curY] == 'F') return 0;
		}
		//
	}
	// finding ways
	return 0;
}
