/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: J.cpp
** Time created: Fri Apr 05 2019 07:17
***********************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 cmp1(i64 A, i64 B) {
    return (A - B);
}

struct point {
    i64 x, y;
    bool operator < (const point& that) const {
        if(cmp1(x, that.x) != 0) return cmp1(x, that.x) < 0;
        return cmp1(y, that.y) < 0;
    }
};

int L, S; vector<point> Large, Small;
/************************************************/

/************** [FUNCTIONS] **************/
int check(point a, point b, point c) {
	i64 val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

	if (val == 0) return 0;       // collinear
	return (val > 0) ? -1: 1;     // counter-clockwise and clockwise
}
void convex_hull(vector<point> &p) {
	int n = p.size();
	sort(p.begin(), p.end());
    vector<point> hull(n*2);
	int k = 0;
	for (int i = 0; i < n; i++) {
		while (k >= 2 && check(hull[k-2], hull[k-1], p[i]) <= 0) k--;
		hull[k++] = p[i];
	}
	for (int i = n-1, t = k+1; i > 0; i--) {
		while (k >= t && check(hull[k-2], hull[k-1], p[i-1]) <= 0) k--;
		hull[k++] = p[i-1];
	}
	hull.resize(k-1); p = hull;
}

void Input() {
	cin >> L; Large.resize(L);
	for (auto &P: Large) cin >> P.x >> P.y;
	cin >> S; Small.resize(S);
	for (auto &P: Small) cin >> P.x >> P.y;
}

void Solve() {
	int ans = 0; convex_hull(Large);
	for (auto lant: Small) {
		bool valid = true;
		i64 sx = lant.x, sy = lant.y;
		int st = 1, en = Large.size() - 1;
		while (en - st + 1 > 2) {
			int mid = (st + en) / 2;
			point A = Large[0], B = Large[mid], C = Large[st];
			i64 a = (B.y - A.y), b = (A.x - B.x);
			i64 c = -(a * A.x + b * A.y);
			i64 Cval = a * C.x + b * C.y + c;
			i64 Sval = a * sx + b * sy + c;
			if ((Cval > 0 && Sval >= 0) || (Cval < 0 && Sval <= 0)) en = mid;
			else st = mid;
		}
		vector<point> Polygon(1, Large[0]);
		for (int i=st; i<=en; i++) Polygon.push_back(Large[i]);
		for (int i=0; i<Polygon.size(); i++) {
			int i1 = (i + 1) % Polygon.size(), i2 = (i + 2) % Polygon.size();
			point A = Polygon[i], B = Polygon[i1], C = Polygon[i2];
			i64 a = (B.y - A.y), b = (A.x - B.x);
			i64 c = -(a * A.x + b * A.y);
			i64 Cval = a * C.x + b * C.y + c;
			i64 Sval = a * sx + b * sy + c;
			if ((Cval > 0 && Sval >= 0) || (Cval < 0 && Sval <= 0)) continue;
			valid = false; break;
		}
		ans += valid;
	}
	cout << ans << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ConfigMonitor();
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/

/************** [MASTER CONTROLS - PHASE 2] **************/
void ConfigMonitor() {
	#ifdef Akikaze
		cout << "Source code by #Team4T-Akikaze.\n";
		cout << "Input: " << ((OImode) ? infile : "stdin");
		cout << " | Output: " << ((OImode) ? outfile : "stdout") << endl << endl;
		cout << "MultiTest-Mode: " << ((MultiTest) ? "ON\n" : "OFF\n");
		cout << "Interactive-Mode: " << ((Interactive) ? "ON\n\n" : "OFF\n\n");
	#else
		if (OImode) {
			freopen(infile, "r", stdin);
			freopen(outfile, "w", stdout);
		}
	#endif
}
/*********************************************************/