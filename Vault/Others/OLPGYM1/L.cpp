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
	int func[13];
	for (int i=1; i<3; i++) cin >> func[i]; cin >> func[11];
	for (int i=4; i<6; i++) cin >> func[i]; cin >> func[12];
	for (int i=7; i<9; i++) cin >> func[i];
	cin >> func[10]; cin >> func[0];
	int s, e; cin >> s >> e;
	if (s == e) cout << "0";
	else if (e > 9) {
		if (!func[10] && !func[11] && !func[12] && !func[e % 10] && !func[e / 10]) cout << "-1";
		else {

		}
	}
	else {
		if (func[e]) cout << "1";
		else if (!func[11] && !func[12]) cout << "-1";
		else if (!func[11]) {
			if (e > s) cout << e-s;
			else cout << (100-e)-s;
		}
		else if (!func[12]) {
			if (s > e) cout << s-e;
			else cout << (100-s)-e;
		}
	}
	//fin.close(); fout.close();
	return 0;
}
