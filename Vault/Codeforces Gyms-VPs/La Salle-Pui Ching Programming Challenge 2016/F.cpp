/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

#include <bits/stdc++.h>
#include <string.h>
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

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
vector<int> zdayYear(3001, 0);
vector<int> zdayMonthN{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
vector<int> zdayMonthL{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
string zd, Abd, Bbd;
int Day0, st, en, ans = 0;
int dd, dm, ad, am, bd, bm;

/** -----EXTENSIVE FUNCTIONS----- **/
int strtoi(string z) {
	int res = 0;
	for (int i=0; i<z.size(); i++) res = res * 10 + (z[i] - '0');
	return res;
}

bool isLeap(int i) {
	return ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0));
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	for (int i=1; i<3001; i++) {
		if (isLeap(i-1)) zdayYear[i] = zdayYear[i-1] + 366;
		else zdayYear[i] = zdayYear[i-1] + 365;
	}
	cin >> zd >> Abd >> Bbd;
	int d = strtoi(zd.substr(0, 2)), m = strtoi(zd.substr(3, 2)), y = strtoi(zd.substr(6, 4));
	if (isLeap(y)) Day0 = zdayYear[y] + zdayMonthL[m-1] + d;
	else Day0 = zdayYear[y] + zdayMonthN[m-1] + d-1;
	st = Day0 + 1; en = Day0 + 2048;
	dd = d; dm = m;
	ad = strtoi(Abd.substr(0, 2)); am = strtoi(Abd.substr(3, 2));
	bd = strtoi(Bbd.substr(0, 2)); bm = strtoi(Bbd.substr(3, 2));
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (int i=st; i<=en; i++) {
		if ((i - Day0) % 100 == 0) {
			ans++; continue;
		}
		int year = upper_bound(zdayYear.begin(), zdayYear.end(), i) - zdayYear.begin() - 1;
		int yearcode = zdayYear[year];
		if (isLeap(year)) {
			if (i - yearcode == zdayMonthL[dm-1] + dd-1) {
				ans++; continue;
			}
			if (i - yearcode == zdayMonthL[am-1] + ad-1) {
				ans++; continue;
			}
			if (i - yearcode == zdayMonthL[bm-1] + bd-1) {
				ans++; continue;
			}
		}
		else {
			if ((dd != 29 || (dd == 29 && dm != 2)) && i - yearcode == zdayMonthN[dm-1] + dd-1) {
				ans++; continue;
			}
			if ((ad != 29 || (ad == 29 && am != 2)) && i - yearcode == zdayMonthN[am-1] + ad-1) {
				ans++; continue;
			}
			if ((bd != 29 || (bd == 29 && bm != 2)) && i - yearcode == zdayMonthN[bm-1] + bd-1) {
				ans++; continue;
			}
		}
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
