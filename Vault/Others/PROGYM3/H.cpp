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


// custom typedef here


// functions here


// File I/O here
string problemName = "";
string in = ".INP";
string out = ".OUT";

int main() {
    //ifstream fin; ofstream fout;
	//fin.open(problemName+in); fout.open(problemName+out);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        char inp[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) cin >> inp[i][j];
        }
        int borderZ = 0, innerO = 0;
        for (int i=0; i<m; i++) {
            if (inp[0][i] == '0') borderZ++;
            if (inp[n-1][i] == '0') borderZ++;
        }
        for (int i=1; i<n-1; i++) {
            if (inp[i][0] == '0') borderZ++;
            if (inp[i][m-1] == '0') borderZ++;
        }
        for (int i=1; i<n-1; i++) {
            for (int j=1; j<m-1; j++) {
                if (inp[i][j] == '1') innerO++;
            }
        }
        if (innerO < borderZ) cout << "-1\n";
        else cout << borderZ << endl;
    }
	//fin.close(); fout.close();
	return 0;
}
