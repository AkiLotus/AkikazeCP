/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

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
i64 K, P;

/** -----EXTENSIVE FUNCTIONS----- **/
bool validPrime(i64 z) {
	if (z < 2) return false;
	for (i64 i=2; i<=sqrt(z); i++) {
		if (z % i == 0) return false;
	}
	return true;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> K >> P;
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	if (!validPrime(P)) {
		cout << 0; return;
	}
	if (K == 1) {
		cout << P; return;
	}
	if (K == 2) {
		if (P * P <= 1000000000LL) cout << P*P;
		else cout << 0; return;
	}
	if (P < 17) {
		vector<i64> prime{2, 3, 5, 7, 11};
		vector<i64> sequence(1, 1);
		i64 mul = 1;
		if (P == 3) {
			mul *= 2;
			prime.erase(prime.begin()+4);
			prime.erase(prime.begin()+3);
			prime.erase(prime.begin()+2);
			prime.erase(prime.begin()+1);
		}
		else if (P == 5) {
			mul *= 2 * 3;
			prime.erase(prime.begin()+4);
			prime.erase(prime.begin()+3);
			prime.erase(prime.begin()+2);
		}
		else if (P == 7) {
			mul *= 2 * 3 * 5;
			prime.erase(prime.begin()+4);
			prime.erase(prime.begin()+3);
		}
		else if (P == 11) {
			mul *= 2 * 3 * 5 * 7; prime.erase(prime.begin()+4);
		}
		else if (P == 13) mul *= 2 * 3 * 5 * 7 * 11;
		for (i64 i=2; i<mul; i++) {
			bool valid = true;
			for (i64 j=0; j<prime.size(); j++) {
				if (i % prime[j] == 0) {
					valid = false; break;
				}
			}
			if (valid) {
				sequence.pub(i);
			}
		}
		i64 ans = P * (((K-1) / sequence.size()) * mul + sequence[(K - 1) % sequence.size()]);
		if (ans > 1000000000LL) cout << 0;
		else cout << ans;
		return;
	}
	if (P * P > 1000000000LL) {
		cout << 0; return;
	}
	// minimum P that could be handled by the below algo: 17
	vector<bool> isPrime(60000005, true);
	vector<bool> affected(60000005, false);
	vector<i64> avail;
	for (i64 i=2; i<10000000; i++) {
		if (isPrime[i]) {
			for (i64 j=2; j<=10000000/i; j++) isPrime[i*j] = false;
		}
	}
	for (i64 i=2; i<P; i++) {
		for (i64 j=1; j<=60000005/i; j++) {
			affected[i*j] = true;
		}
	}
	for (i64 i=1; i<=min(1000000000/P, 60000005LL); i++) {
		if (!affected[i]) avail.pub(i);
	}
	if (K > avail.size()) cout << 0;
	else cout << P * avail[K-1];
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
