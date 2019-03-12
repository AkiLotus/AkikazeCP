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


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	string z; cin >> z; int n = z.size();
	int open = 0, close = 0;
	int oR, cr;
	for (int i=0; i<n; i++) {
		if (z[i] == '(') open++;
		else if (z[i] == ')') close++;
	}
	if (open == close) {
		if ((n - open - close) % 2 != 0) {
			cout << "Impossible"; return 0;
		}
		oR = (n - open - close) / 2; cr = oR;
	}
	else if (open > close) {
		int rem = n - open - close;
		int diff = open - close;
		if (rem - diff < 0 || (rem - diff) % 2 != 0) {
			cout << "Impossible"; return 0;
		}
		oR = (rem - diff) / 2; cr = (rem + diff) / 2;
	}
	else if (close > open) {
		int rem = n - open - close;
		int diff = close - open;
		if (rem - diff < 0 || (rem - diff) % 2 != 0) {
			cout << "Impossible"; return 0;
		}
		oR = (rem + diff) / 2; cr = (rem - diff) / 2;
	}
	int status = 0;
	for (i64 i=0; i<n; i++) {
		if (z[i] == '?') {
			if (oR > 0) {
				z[i] = '('; oR--;
			}
			else {
				z[i] = ')'; cr--;
			}
		}
		if (z[i] == '(') status++; else status--;
		if (status < 0) {
			cout << "Impossible"; return 0;
		}
	}
	cout << z;
	return 0;
}