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
        int n, s; cin >> n >> s;
        if (n % 2 == 0 && s % 2 != 0) cout << "-1\n";
        else if (n > 1 && s == 1) cout << "-1\n";
        else if (s > 9*n) cout << "-1\n";
        else if (n % 2 == 0) {
            string half1 = ""; s /= 2;
            while (s > 0 && half1.size() < n/2) {
                if (s > 9) {
                    half1 += "9"; s-= 9;
                }
                else {
                    half1 += char(48+s); s = 0;
                }
            }
            half1.insert(half1.size(), n/2-half1.size(), '0');
            string half2 = half1; reverse(half2.begin(), half2.end());
            cout << half1 << half2 << endl;
        }
        else {
            string half1 = ""; int rem = s % 2;
            s /= 2;
            while (s > 0 && half1.size() < n/2) {
                if (s > 9) {
                    half1 += "9"; s-= 9;
                }
                else {
                    half1 += char(48+s); s = 0;
                }
            }
            rem += s*2;
            half1.insert(half1.size(), n/2-half1.size(), '0');
            string half2 = half1; reverse(half2.begin(), half2.end());
            char remchar = char(48+rem);
            cout << half1 << remchar << half2 << endl;
        }
    }
	//fin.close(); fout.close();
	return 0;
}
