/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: H.cpp
// Time created: Fri May 31 2019 14:25

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
const ld Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
ld keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 1;
int Interactive = 0;

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int C, P, test = 0; vector<pair<ld, ld>> sensors, locations;
/************************************************/

/************** [FUNCTIONS] **************/
bool cw(pair<ld, ld> &a, pair<ld, ld> &b, pair<ld, ld> &c) {
	return a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second) < 0;
}

bool ccw(pair<ld, ld> &a, pair<ld, ld> &b, pair<ld, ld> &c) {
	return a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second) > 0;
}

void convex_hull(vector<pair<ld, ld>> &a) {
	if (a.size() <= 1) return;

	sort(a.begin(), a.end());
	pair<ld, ld> p1 = a[0], p2 = a.back();

	vector<pair<ld, ld>> up, down;
	up.push_back(p1); down.push_back(p1);

	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back(a[i]);
		}
	}

	a.clear();
	for (size_t i=0; i<up.size(); ++i) a.push_back(up[i]);
	for (size_t i=down.size()-2; i>0; --i) a.push_back(down[i]);
}

bool beingInside(pair<ld, ld> &Point, vector<pair<ld, ld>> &Poly) {
	ld x = Point.first, y = Point.second;
	int st = 1, en = Poly.size() - 1;
	while (en - st + 1 > 2) {
		int mid = (st + en) / 2;
		pair<ld, ld> A = Poly[0], B = Poly[mid], C = Poly[st];
		ld a = (B.second - A.second), b = (A.first - B.first);
		ld c = -(a * A.first + b * A.second);
		ld Cval = a * C.first + b * C.second + c;
		ld Sval = a * x + b * y + c;
		if ((Cval > +EPS && Sval >= -EPS) || (Cval < -EPS && Sval <= +EPS)) en = mid;
		else st = mid;
	}
	vector<pair<ld, ld>> Polygon(1, Poly[0]);
	for (int i=st; i<=en; i++) Polygon.push_back(Poly[i]);
	for (int i=0; i<Polygon.size(); i++) {
		int i1 = (i + 1) % Polygon.size(), i2 = (i + 2) % Polygon.size();
		pair<ld, ld> A = Polygon[i], B = Polygon[i1], C = Polygon[i2];
		ld a = (B.second - A.second), b = (A.first - B.first);
		ld c = -(a * A.first + b * A.second);
		ld Cval = a * C.first + b * C.second + c;
		ld Sval = a * x + b * y + c;
		if ((Cval > +EPS && Sval >= -EPS) || (Cval < -EPS && Sval <= +EPS)) continue;
		return false;
	}
	return true;
}

void Input() {
	cin >> C >> P; sensors.clear(); locations.clear();
	sensors.resize(C); locations.resize(P);
	for (auto &Pair: sensors) cin >> Pair.first >> Pair.second;
	for (auto &Pair: locations) cin >> Pair.first >> Pair.second;
}

void Solve() {
	convex_hull(sensors);
	C = sensors.size();

	cout << "Case " << (++test) << endl;
	int id = (min_element(sensors.begin(), sensors.end()) - sensors.begin()) + C;
	for (int i=id; i>=id-C; i--) {
		pair<ld, ld> Pair = sensors[i % C];
		cout << Pair.first << " " << Pair.second << endl;
	}
	for (auto Pair: locations) {
		cout << Pair.first << " " << Pair.second;
		if (beingInside(Pair, sensors)) cout << " is unsafe!\n";
		else cout << " is safe!\n";
	}
	cout << endl;
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