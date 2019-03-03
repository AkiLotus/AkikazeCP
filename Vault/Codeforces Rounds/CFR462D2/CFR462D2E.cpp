/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/
typedef pair<ld, ld> pdd;
typedef pair<pdd, ld> ppd;

/** -----GLOBAL VARIABLES----- **/
i64 n; vector<ppd> a;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
}

void ProSolve() {
	if (n == 1) {cout << "2"; return;}
	if (n == 2) {
		if (sqrt((a[0].fi.fi - a[1].fi.fi) * (a[0].fi.fi - a[1].fi.fi) + (a[0].fi.se - a[1].fi.se) * (a[0].fi.se - a[1].fi.se)) + a[1].se <= a[0].se) {
			cout << "3"; return;
		}
		if (sqrt((a[0].fi.fi - a[1].fi.fi) * (a[0].fi.fi - a[1].fi.fi) + (a[0].fi.se - a[1].fi.se) * (a[0].fi.se - a[1].fi.se)) + a[0].se <= a[1].se) {
			cout << "3"; return;
		}
		if ((a[0].fi.fi - a[1].fi.fi) * (a[0].fi.fi - a[1].fi.fi) + (a[0].fi.se - a[1].fi.se) * (a[0].fi.se - a[1].fi.se) >= (a[0].se + a[1].se) * (a[0].se + a[1].se)) {
			cout << "3";
		}
		else cout << "4";
		return;
	}
	vector<vector<bool>> overlap(3, vb(3, true));
	vector<vector<bool>> intersect(3, vb(3, false));
	vector<vector<bool>> within(3, vb(3, false));
	for (i64 i=0; i<n-1; i++) {
		for (i64 j=i+1; j<n; j++) {
			if ((a[i].fi.fi - a[j].fi.fi) * (a[i].fi.fi - a[j].fi.fi) + (a[i].fi.se - a[j].fi.se) * (a[i].fi.se - a[j].fi.se) >= (a[i].se + a[j].se) * (a[i].se + a[j].se)) {
				overlap[i][j] = false;
			}
			if ((a[i].fi.fi - a[j].fi.fi) * (a[i].fi.fi - a[j].fi.fi) + (a[i].fi.se - a[j].fi.se) * (a[i].fi.se - a[j].fi.se) == (a[i].se + a[j].se) * (a[i].se + a[j].se)) {
				intersect[i][j] = true;
			}
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=i; j<n; j++) {
			if (i == j) continue;
			if (sqrt((a[i].fi.fi - a[j].fi.fi) * (a[i].fi.fi - a[j].fi.fi) + (a[i].fi.se - a[j].fi.se) * (a[i].fi.se - a[j].fi.se)) + a[i].se <= a[j].se) {
				within[i][j] = true;
			}
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			if (i == j) continue;
			i64 k = 0; while (k == i || k == j) k++;
			if (within[i][j]) {
				if (within[j][k]) {cout << "4"; return;}
				else if (within[k][j]) {
					if (within[i][k] || within[k][i]) {
						cout << "4"; return;
					}
					if (intersect[j][k]) {cout << "4"; return;}
					if (overlap[j][k]) {cout << "5"; return;}
				}
				if (within[k][i]) {
					cout << "4"; return;
				}
				if (within[i][k]) {
					if (within[j][k] || within[k][j]) {
						cout << "4"; return;
					}
					cout << "5"; return;
				}
				if (!overlap[i][k] && !overlap[j][k]) {cout << "4"; return;}
				if (!overlap[i][k] && overlap[j][k]) {cout << "5"; return;}
				if (overlap[i][k] && overlap[j][k]) {cout << "6"; return;}
				return;
			}
		}
	}
	if (intersect[0][1] && intersect[0][2] && intersect[1][2]) {cout << "5"; return;}
	if (intersect[0][1] && overlap[0][2] && overlap[1][2]) {cout << "6"; return;}
	if (overlap[0][1] && intersect[0][2] && overlap[1][2]) {cout << "6"; return;}
	if (overlap[0][1] && overlap[0][2] && intersect[1][2]) {cout << "6"; return;}
	if (!overlap[0][1] && !overlap[0][2] && !overlap[1][2]) {cout << "4"; return;}
	if (!overlap[0][1] && !overlap[0][2] && overlap[1][2]) {cout << "5"; return;}
	if (!overlap[0][1] && overlap[0][2] && !overlap[1][2]) {cout << "5"; return;}
	if (overlap[0][1] && !overlap[0][2] && !overlap[1][2]) {cout << "5"; return;}
	if (overlap[0][1] && overlap[0][2] && !overlap[1][2]) {cout << "6"; return;}
	if (overlap[0][1] && !overlap[0][2] && overlap[1][2]) {cout << "6"; return;}
	if (!overlap[0][1] && overlap[0][2] && overlap[1][2]) {cout << "6"; return;}
	if (overlap[0][1] && overlap[0][2] && overlap[1][2]) {cout << "8"; return;}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput(); ProSolve(); return 0;
}