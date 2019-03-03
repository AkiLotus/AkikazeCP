// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// global variables here
vector<i64> factorial(100005, 1);
vector<i64> ftrialPow(100005, 1);

// custom typedef here


// functions here
i64 Pow_(i64 x, i64 k) {
    if (k == 0) return 1;
    if (k == 1) return x % MOD;
    i64 tmp = Pow_(x, k/2);
    tmp = (tmp * tmp) % MOD;
    if (k % 2 == 1) tmp = (tmp * x) % MOD;
    return tmp;
}

void dataInitialize() {
    for (i64 i=2; i<100005; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
        ftrialPow[i] = Pow_(factorial[i], MOD-2);
    }
}

i64 nCr(i64 a, i64 b) {
    return (((factorial[a] * ftrialPow[b]) % MOD) * ftrialPow[a-b]) % MOD;
}

// File I/O here
string problemName = "";
string in = ".INP";
string out = ".OUT";

int main() {
    //ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	dataInitialize();
    int T; cin >> T;
    while (T--) {
        i64 a, b; cin >> a >> b;
        cout << (2 * nCr(a-1, b)) % MOD << endl;
    }
	//fin.close(); fout.close();
	return 0;
}
