/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: I.cpp
// Time created: Sun Oct 13 2019 04:18

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
int MultiTest = 1;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
i64 w, k;
/************************************************/

/************** [FUNCTIONS] **************/
i64 getAll(i64 order) {
	if (order < 0) return 0;
	i64 Mn = 1, Mx = 9, res = 0;
	for (i64 i=1; i<=15; i++) {
		i64 localMin = (Mn - order) / w;
		i64 localMax = Mx / w;
		while (localMin * w - w >= Mn) localMin--;
		while (localMin * w + order < Mn) localMin++;
		while (localMax * w + order + w <= Mx) localMax++;
		while (localMax * w > Mx) localMax--;
		if (localMin <= localMax) {
			res += (max(localMax - localMin + 1, 0LL) * i) * (order + 1);
			res -= max(Mn - localMin * w, 0LL) * i;
			res -= max(localMax * w + order - Mx, 0LL) * i;
		}
		Mn *= 10; Mx = Mx * 10 + 9;
	}
	if (1000000000000000LL % w <= order) res += 16;
	return res;
}

i64 binsearch_order(i64 L, i64 R) {
	i64 res = L - 1;
	while (L <= R) {
		i64 x = (L + R) / 2;
		if (getAll(x) < k) {res = x; L = x + 1;}
		else R = x - 1;
	}
	return res;
}

i64 getInOrder(i64 order, i64 num) {
	i64 Mn = 1, Mx = min(9LL, num), res = 0;
	for (i64 i=1; (i<=15 && Mn <= num); i++) {
		i64 localMin = (Mn / w) * w + order;
		i64 localMax = (Mx / w) * w + order;
		while (localMin - w >= Mn) localMin -= w;
		while (localMin < Mn) localMin += w;
		while (localMax + w <= Mx) localMax += w;
		while (localMax > Mx) localMax -= w;
		res += max((localMax - localMin) / w + 1, 0LL) * i;
		Mn *= 10; Mx = min(Mx * 10 + 9, num);
	}
	if (1000000000000000LL % w == order && num == 1000000000000000LL) res += 16;
	return res;
}

i64 binsearch_number(i64 L, i64 R, i64 order) {
	i64 res = L / w - 1; L /= w; R /= w;
	while (L <= R) {
		i64 x = (L + R) / 2;
		if (getInOrder(order, x * w + order) < k) {res = x; L = x + 1;}
		else R = x - 1;
	}
	return (res * w + order);
}

void Input() {
	cin >> w >> k;
}

void Solve() {
	i64 order = binsearch_order(0, w-1);
	i64 Mn = order + 1;
	i64 Mx = (1000000000000000LL / w) * w + order + 1;
	if (Mn < 1) Mn += w;
	if (Mx > 1000000000000000LL) Mx -= w;
	k -= getAll(order);
	i64 number = binsearch_number(Mn, Mx, order+1);
	k -= getInOrder(order+1, number);
	string s = to_string(number + w);
	cout << s[k-1] << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifndef Akikaze
		if (OImode) {
			assert(freopen(infile, "r", stdin));
			assert(freopen(outfile, "w", stdout));
		}
	#endif
	
	//ios_base::sync_with_stdio(false);
	//if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/