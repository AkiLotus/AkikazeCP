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
	int t; cin >> t;
	while (t--) {
		int bed = 0, kit = 0, liv = 0;
		int n; cin >> n;
		while (n--) {
			string z; cin >> z;
			if (z.size() >= 3 && (z[0] == 'b' || z[0] == 'B') && (z[1] == 'e' || z[1] == 'E') && (z[2] == 'd' || z[2] == 'D')) bed++;
			else if (z.size() >= 7 && (z[0] == 'k' || z[0] == 'K') && (z[1] == 'i' || z[1] == 'I') && (z[2] == 't' || z[2] == 'T') && (z[3] == 'c' || z[3] == 'C') && (z[4] == 'h' || z[4] == 'H') && (z[5] == 'e' || z[5] == 'E') && (z[6] == 'n' || z[6] == 'N')) kit++;
			else if (z.size() >= 6 && (z[0] == 'l' || z[0] == 'L') && (z[1] == 'i' || z[1] == 'I') && (z[2] == 'v' || z[2] == 'V') && (z[3] == 'i' || z[3] == 'I') && (z[4] == 'n' || z[4] == 'N') && (z[5] == 'g' || z[5] == 'G')) liv++;
		}
		cout << min(min(bed/2, kit), liv) << endl;
	}
	//fin.close(); fout.close();
	return 0;
}
