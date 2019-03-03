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
i64 N, T, ans = 0; vi A(32, 0);
vector<pii> FirstSeg, SecondSeg;

/** -----EXTENSIVE FUNCTIONS----- **/
void Try1(i64 pos, i64 sum, i64 unused) {
	if (pos >= N/2 - 1) {
		if (pos == N/2 - 1) FirstSeg.pub(mp(sum, unused));
		return;
	}
	Try1(pos+1, sum, min(unused, pos+1));
	Try1(pos+1, sum+A[pos+1], min(unused, LINF));
}

void Try2(i64 pos, i64 sum, i64 unused) {
	if (pos >= N - 1) {
		if (pos == N - 1) SecondSeg.pub(mp(sum, unused));
		return;
	}
	Try2(pos+1, sum, min(unused, pos+1));
	Try2(pos+1, sum+A[pos+1], min(unused, LINF));
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> T;
}

void ProSolve() {
	while (N > 0 || T > 0) {
		for (i64 i=0; i<N; i++) cin >> A[i]; ans = 0;
		sort(A.begin(), A.begin()+N);
		//for (i64 i=0; i<N; i++) cout << A[i] << " "; cout << endl;
		FirstSeg.clear(); SecondSeg.clear();
		Try1(0, 0, 0); Try1(0, A[0], LINF);
		Try2(N/2, 0, N/2); Try2(N/2, A[N/2], LINF);
		sort(FirstSeg.begin(), FirstSeg.end());
		sort(SecondSeg.begin(), SecondSeg.end());
		//cout << FirstSeg << endl << SecondSeg << endl;
		if (!FirstSeg.empty()) {
			for (i64 i=0; i<FirstSeg.size()-1; i++) {
				//tracker2(FirstSeg[i].fi, FirstSeg[i].se);
				i64 firstUnused = FirstSeg[i].se;
				i64 L = lower_bound(SecondSeg.begin(), SecondSeg.end(), mp(T+1-A[firstUnused]-FirstSeg[i].fi, 0LL)) - SecondSeg.begin();
				i64 R = lower_bound(SecondSeg.begin(), SecondSeg.end(), mp(T+1-FirstSeg[i].fi, 0LL)) - SecondSeg.begin();
				ans += (R - L); if (FirstSeg[i].fi + SecondSeg[L].fi == 0) ans--;
				//cout << "ans = " << ans << endl;
			}
		}
		i64 fisum = 0;
		if (!FirstSeg.empty()) fisum = FirstSeg[FirstSeg.size()-1].fi;
		for (i64 i=0; i<SecondSeg.size(); i++) {
			//tracker3(fisum, SecondSeg[i].fi, SecondSeg[i].se);
			i64 additional = 0; if (SecondSeg[i].se != LINF) additional = A[SecondSeg[i].se];
			if (fisum + SecondSeg[i].fi > 0 && fisum + SecondSeg[i].fi <= T && fisum + SecondSeg[i].fi + additional > T) ans++;
			//cout << "ans = " << ans << endl;
		}
		cout << ans << endl;
		cin >> N >> T;
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