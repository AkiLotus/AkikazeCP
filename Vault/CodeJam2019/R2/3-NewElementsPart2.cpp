/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: 3-NewElementsPart2.cpp
// Time created: Sat May 18 2019 14:36

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
const long double EPS = 0.000000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 1;
int Interactive = 0;

char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int test = 0; int N; vector<i64> C, J;
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

pair<ld, ld> findIntersect(pair<pair<i64, i64>, i64> line1, pair<pair<i64, i64>, i64> line2) {
	i64 a1 = line1.first.first, b1 = line1.first.second, c1 = -line1.second;
	i64 a2 = line2.first.first, b2 = line2.first.second, c2 = -line2.second;

	i64 D = a1 * b2 - a2 * b1;
	i64 Dx = c1 * b2 - c2 * b1;
	i64 Dy = a1 * c2 - a2 * c1;

	if (D == 0) return make_pair(-1.0L, -1.0L);

	ld x = 1.0L * Dx / D, y = 1.0L * Dy / D;
	return make_pair(x, y);
}

bool withinNegative(pair<pair<i64, i64>, i64> line, pair<ld, ld> point) {
	i64 a = line.first.first, b = line.first.second, c = line.second;
	ld x = point.first, y = point.second;
	return (1.0L * a * x + 1.0L * b * y + 1.0L * c < EPS);
}

bool InterceptedPoint(pair<ld, ld> &M, pair<ld, ld> &N, pair<ld, ld> &P, pair<ld, ld> &Q, pair<ld, ld> &NewPoint) {
	ld a1 = N.second - M.second, b1 = M.first - N.first;
	ld c1 = a1 * M.first + b1 * M.second;

	ld a2 = Q.second - P.second, b2 = P.first - Q.first;
	ld c2 = a2 * P.first + b2 * P.second;

	ld D = a1 * b2 - a2 * b1;
	ld Dx = c1 * b2 - c2 * b1;
	ld Dy = a1 * c2 - a2 * c1;

	if (abs(D) <= EPS) return false;

	ld x = Dx / D, y = Dy / D;
	if ((x - min(M.first, N.first)) / x < -EPS || (x - max(M.first, N.first)) / x > +EPS) return false;
	if ((y - min(M.second, N.second)) / y < -EPS || (y - max(M.second, N.second)) / y > +EPS) return false;
	NewPoint = make_pair(x, y); return true;
}

pair<i64, i64> getRange(vector<pair<ld, ld>> &Polygon, i64 x) {
	pair<pair<ld, ld>, ld> curLine = {{-1.0L, 0.0L}, 1.0L * x};
	ld MinY = (ld)+1e40, MaxY = (ld)-1e40;
	for (int i=0; i<Polygon.size(); i++) {
		pair<ld, ld> ptA = Polygon[i], ptB = Polygon[(i+1) % Polygon.size()];
		pair<ld, ld> ptC = {1.0L * x, 1.0L * -1e40}, ptD = {1.0L * x, 1.0L * +1e40};
		pair<ld, ld> newPoint;
		if (InterceptedPoint(ptA, ptB, ptC, ptD, newPoint)) {
			MinY = min(MinY, newPoint.second);
			MaxY = max(MaxY, newPoint.second);
		}
	}
	i64 iMin = (i64)(MinY) + 1, iMax = MaxY;
	return make_pair(iMin, iMax);
}

i64 binsearch(i64 L, i64 R, vector<pair<ld, ld>> &Polygon) {
	i64 res = -1LL;
	while (L <= R) {
		i64 mid = (L + R) / 2;
		pair<i64, i64> yrange = getRange(Polygon, mid);
		if (yrange.first < yrange.second) {res = mid; R = mid - 1;}
		else L = mid + 1;
	}
	return res;
}

void Input() {
	cin >> N; C.clear(); J.clear();
	C.resize(N); J.resize(N);
	for (int i=0; i<N; i++) cin >> C[i] >> J[i];
}

void Solve() {
	vector<pair<pair<i64, i64>, i64>> Ineq;
	vector<pair<ld, ld>> Polygon;
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<N; j++) {
			Ineq.push_back({{C[i] - C[j], J[i] - J[j]}, 0});
		}
	}
	Ineq.push_back({{-1LL, 0LL}, 0LL}); Ineq.push_back({{0LL, -1LL}, 0LL});
	Ineq.push_back({{1LL, 0LL}, -(LLONG_MAX - 16)}); Ineq.push_back({{0LL, 1LL}, -(LLONG_MAX - 16)});
	for (int i=0; i<Ineq.size(); i++) {
		for (int j=i+1; j<Ineq.size(); j++) {
			pair<ld, ld> point = findIntersect(Ineq[i], Ineq[j]);
			bool solutionField = true;
			for (auto line: Ineq) {
				if (!withinNegative(line, point)) {
					solutionField = false;
					break;
				}
			}
			if (solutionField) Polygon.push_back(point);
		}
	}
	convex_hull(Polygon);
	if (Polygon.size() < 3) {
		cout << "Case #" << (++test);
		cout << ": IMPOSSIBLE\n"; return;
	}
	pair<ld, ld> MinXPoint = *min_element(Polygon.begin(), Polygon.end());
	pair<ld, ld> MaxXPoint = *max_element(Polygon.begin(), Polygon.end());
	i64 MinX = (i64)MinXPoint.first + 1, MaxX = (i64)MaxXPoint.first;
	i64 x = binsearch(max(1LL, MinX), min(MaxX, LLONG_MAX - 16), Polygon);
	if (x == -1) {
		cout << "Case #" << (++test);
		cout << ": IMPOSSIBLE\n"; return;
	}
	i64 y = getRange(Polygon, x).first;
	cout << "Case #" << (++test) << ": " << x << " " << y << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
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
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/