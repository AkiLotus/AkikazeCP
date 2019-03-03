/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	H△G x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	H△G x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	青色フィルム (H△G) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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


/** -----GLOBAL VARIABLES----- **/
vector<vb> grass(5, vb(5, true)), vis(5, vb(5, false));
i64 K, ans = 0;

/** -----EXTENSIVE FUNCTIONS----- **/
void DFS(i64 xA, i64 yA, i64 xB, i64 yB, i64 cnt, i64 rem) {
	if (xA == xB && yA == yB) {if (rem == 1) ans++; return;}
	if (rem == -1) return;
	vis[xA][yA] = true; vis[xB][yB] = true;
	if (xA - 1 >= 0 && !vis[xA-1][yA] && grass[xA-1][yA] && xB - 1 >= 0 && !vis[xB-1][yB] && grass[xB-1][yB]) DFS(xA-1, yA, xB-1, yB, cnt+1, rem-2);
	if (xA - 1 >= 0 && !vis[xA-1][yA] && grass[xA-1][yA] && yB - 1 >= 0 && !vis[xB][yB-1] && grass[xB][yB-1]) DFS(xA-1, yA, xB, yB-1, cnt+1, rem-2);
	if (xA - 1 >= 0 && !vis[xA-1][yA] && grass[xA-1][yA] && xB + 1 <= 4 && !vis[xB+1][yB] && grass[xB+1][yB]) DFS(xA-1, yA, xB+1, yB, cnt+1, rem-2);
	if (xA - 1 >= 0 && !vis[xA-1][yA] && grass[xA-1][yA] && yB + 1 <= 4 && !vis[xB][yB+1] && grass[xB][yB+1]) DFS(xA-1, yA, xB, yB+1, cnt+1, rem-2);
	
	if (yA - 1 >= 0 && !vis[xA][yA-1] && grass[xA][yA-1] && xB - 1 >= 0 && !vis[xB-1][yB] && grass[xB-1][yB]) DFS(xA, yA-1, xB-1, yB, cnt+1, rem-2);
	if (yA - 1 >= 0 && !vis[xA][yA-1] && grass[xA][yA-1] && yB - 1 >= 0 && !vis[xB][yB-1] && grass[xB][yB-1]) DFS(xA, yA-1, xB, yB-1, cnt+1, rem-2);
	if (yA - 1 >= 0 && !vis[xA][yA-1] && grass[xA][yA-1] && xB + 1 <= 4 && !vis[xB+1][yB] && grass[xB+1][yB]) DFS(xA, yA-1, xB+1, yB, cnt+1, rem-2);
	if (yA - 1 >= 0 && !vis[xA][yA-1] && grass[xA][yA-1] && yB + 1 <= 4 && !vis[xB][yB+1] && grass[xB][yB+1]) DFS(xA, yA-1, xB, yB+1, cnt+1, rem-2);
	
	if (xA + 1 <= 4 && !vis[xA+1][yA] && grass[xA+1][yA] && xB - 1 >= 0 && !vis[xB-1][yB] && grass[xB-1][yB]) DFS(xA+1, yA, xB-1, yB, cnt+1, rem-2);
	if (xA + 1 <= 4 && !vis[xA+1][yA] && grass[xA+1][yA] && yB - 1 >= 0 && !vis[xB][yB-1] && grass[xB][yB-1]) DFS(xA+1, yA, xB, yB-1, cnt+1, rem-2);
	if (xA + 1 <= 4 && !vis[xA+1][yA] && grass[xA+1][yA] && xB + 1 <= 4 && !vis[xB+1][yB] && grass[xB+1][yB]) DFS(xA+1, yA, xB+1, yB, cnt+1, rem-2);
	if (xA + 1 <= 4 && !vis[xA+1][yA] && grass[xA+1][yA] && yB + 1 <= 4 && !vis[xB][yB+1] && grass[xB][yB+1]) DFS(xA+1, yA, xB, yB+1, cnt+1, rem-2);
	
	if (yA + 1 <= 4 && !vis[xA][yA+1] && grass[xA][yA+1] && xB - 1 >= 0 && !vis[xB-1][yB] && grass[xB-1][yB]) DFS(xA, yA+1, xB-1, yB, cnt+1, rem-2);
	if (yA + 1 <= 4 && !vis[xA][yA+1] && grass[xA][yA+1] && yB - 1 >= 0 && !vis[xB][yB-1] && grass[xB][yB-1]) DFS(xA, yA+1, xB, yB-1, cnt+1, rem-2);
	if (yA + 1 <= 4 && !vis[xA][yA+1] && grass[xA][yA+1] && xB + 1 <= 4 && !vis[xB+1][yB] && grass[xB+1][yB]) DFS(xA, yA+1, xB+1, yB, cnt+1, rem-2);
	if (yA + 1 <= 4 && !vis[xA][yA+1] && grass[xA][yA+1] && yB + 1 <= 4 && !vis[xB][yB+1] && grass[xB][yB+1]) DFS(xA, yA+1, xB, yB+1, cnt+1, rem-2);
	vis[xA][yA] = false; vis[xB][yB] = false;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> K;
	for (i64 i=0; i<K; i++) {
		i64 x, y; cin >> x >> y; x--; y--;
		grass[x][y] = false;
	}
}

void ProSolve() {
	if (K % 2 != 0) {cout << "0"; return;}
	DFS(0, 0, 4, 4, 0, 25-K);
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << fixed << setprecision(18) << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}