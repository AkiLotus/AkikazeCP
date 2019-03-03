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
#define INF 1000000000LL
#define LINF 1000000000000000000LL
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

/** -----IDEAS/ALGORITHMS----- **/


/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
i64 N, M;
vector<i64> A, B;
bool overriden = false;
i64 ans = 1;


/** -----EXTENSIVE FUNCTIONS----- **/
i64 modPow(i64 a, i64 b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	i64 tmp = modPow(a, b/2);
	if (b % 2 == 0) {
		i64 res = tmp * tmp;
		if (res >= INF) {
			res %= INF; overriden = true;
		}
		return res;
	}
	i64 res = tmp * tmp;
	if (res >= INF) {
		res %= INF; overriden = true;
	}
	res *= a;
	if (res >= INF) {
		res %= INF; overriden = true;
	}
	return res;
}

/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	cin >> N; A.resize(N);
	for (i64 i=0; i<N; i++) cin >> A[i];
	cin >> M; B.resize(M);
	for (i64 i=0; i<M; i++) cin >> B[i];
}

void ProSolve() {
	map<i64, i64> Ma, Mb;
	vector<i64> distA, distB;
	for (i64 i=0; i<N; i++) {
		//tracker1(A[i]);
		for (i64 j=2; j<=sqrt(A[i]); j++) {
			if (A[i] % j == 0) {
				//cout << "Ma[" << j << "] = " << Ma[j] << endl;
				if (Ma[j] == 0) distA.pub(j);
				while (A[i] % j == 0) {
					A[i] /= j;
					Ma[j]++;
				}
			}
		}
		if (A[i] != 1) {
			if (Ma[A[i]] == 0) distA.pub(A[i]);
			Ma[A[i]]++; A[i] = 1;
		}
	}
	for (i64 i=0; i<M; i++) {
		//tracker1(B[i]);
		for (i64 j=2; j<=sqrt(B[i]); j++) {
			if (B[i] % j == 0) {
				//cout << "Mb[" << j << "] = " << Mb[j] << endl;
				if (Mb[j] == 0) distB.pub(j);
				while (B[i] % j == 0) {
					B[i] /= j;
					Mb[j]++;
				}
			}
		}
		if (B[i] != 1) {
			if (Mb[B[i]] == 0) distB.pub(B[i]);
			Mb[B[i]]++; B[i] = 1;
		}
	}
	for(i64 i=0; i<distA.size(); i++) {
		i64 exp = min(Ma[distA[i]], Mb[distA[i]]);
		//cout << distA[i] << " ^ " << exp << endl;
		ans *= modPow(distA[i], exp);
		if (ans >= INF) {
			overriden = true;
			ans %= INF;
		}
	}
	if (!overriden) cout << ans;
	else {
		string tmp = "";
		while (ans > 0) {
			char z = char(48+ans%10);
			tmp.insert(0, 1, z);
			ans /= 10;
		}
		tmp.insert(0, 9-tmp.size(), '0');
		cout << tmp;
	}
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
