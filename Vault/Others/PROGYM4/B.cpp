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
	ios_base::sync_with_stdio(0);// cin.tie(NULL);
	// code here
	int k; cin >> k;
	vector<string> nick(k), gang(k);
	vector<vector<int>> cc;
	vector<vector<int>> artcc;
	vector<int> point(k, 999999999);
	for (int i=0; i<k; i++) {
		vector<int> tmp(256, 0);
		vector<int> tmp2(256, 0);
		cc.pub(tmp);
		artcc.pub(tmp2);
	}
	for (int i=0; i<k; i++) {
		cin >> nick[i] >> gang[i];
		for (int j=0; j<nick[i].size(); j++) {
			cc[i][int(nick[i][j])]++;
		}
		for (int j=0; j<gang[i].size(); j++) {
			cc[i][int(gang[i][j])]++;
		}
	}
	int m, n; char z;
	for (int i=0; i<k; i++) {
		cin >> m >> n;
		for (int x=0; x<m*n; x++) {
			cin >> z;
			artcc[i][int(z)]++;
		}
		for (int j=0; j<256; j++)
			if (cc[i][j] != 0) point[i] = min(point[i], artcc[i][j] / cc[i][j]);
	}
	int winner = max_element(point.begin(), point.end()) - point.begin();
	cout << nick[winner] << " " << gang[winner];
	//fin.close(); fout.close();
	return 0;
}
