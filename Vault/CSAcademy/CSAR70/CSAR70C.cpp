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


/** -----GLOBAL VARIABLES----- **/
i64 N, M; vector<vi> edge, dist;
vi a, b, c; map<pii, i64> Map;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M; edge.resize(N, vi(N, 1e7));
	dist.resize(N, vi(N, LINF));
	a.resize(M); b = a; c = a;
	for (i64 i=0; i<M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--; Map[mp(a[i],b[i])] = c[i]; Map[mp(b[i],a[i])] = c[i];
		edge[a[i]][b[i]] = c[i]; edge[b[i]][a[i]] = c[i];
		dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
		dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
	}
}

void ProSolve() {
	for (i64 k=0; k<N; k++) {
		for (i64 i=0; i<N; i++) {
			for (i64 j=0; j<N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (i64 i=0; i<N; i++) {
		for (i64 j=i+1; j<N; j++) {
			if (Map[mp(i,j)] && dist[i][j] != Map[mp(i,j)]) {
				cout << "-1"; return;
			}
		}
	}
	cout << (N * (N - 1) / 2) << endl;
	for (i64 i=0; i<N; i++) {
		for (i64 j=i+1; j<N; j++) {
			cout << i+1 << " " << j+1 << " " << edge[i][j] << endl;
		}
	}
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