// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

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

// custom typedef here


// global variables here
int T, cas = 0;
i64 MahonianTriangle[3333][3333];
i64 sumMT[3333][3333];

// functions here


/* -----COMPULSORY FUNCTIONS----- */
void VarInput() {
	cin >> T;
	for (i64 i=0; i<3333; i++) {
		MahonianTriangle[i][0] = 1;
		sumMT[i][0] = i;
	}
	for (i64 i=0; i<3333; i++) sumMT[0][i] = 1;
	for (i64 i=1; i<3333; i++) {
		i64 j = 1;
		for (j=1; j<min(i*(i+1)/2+1, 3333LL); j++) {
			if (j - i <= 0) MahonianTriangle[i][j] = sumMT[i-1][j];
			else MahonianTriangle[i][j] = sumMT[i-1][j] - sumMT[i-1][j-i-1];
			sumMT[i][j] = (sumMT[i][j-1] + MahonianTriangle[i][j]) % 10007;
		}
		for (; j<3333; j++) sumMT[i][j] = sumMT[i][j-1];
		if (i<10) {for (j=0; j<10; j++) cout << sumMT[i][j] << " "; cout << endl;}
	}
	for (i64 i=0; i<10; i++) {
		for (i64 j=0; j<10; j++) cout << MahonianTriangle[i][j] << " ";
		cout << endl;
	}
}

void ProSolve() {
	i64 N, K; cin >> N >> K;
	i64 ans = 0;
	for (i64 i=K; i<=(N-2)*(N-1)/2; i++) ans = (ans + MahonianTriangle[N-1][i]) % 10007;
	cout << "Case " << ++cas << ": " << ans << endl;
}

/* -----MAIN FUNCTION----- */
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	while (T--) ProSolve();
	return 0;
}
