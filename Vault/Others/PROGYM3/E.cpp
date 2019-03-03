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
i64 modPow(i64 x, i64 k) {
	if (k == 0) return 1;
	if (k == 1) return x % MOD;
	i64 tmp = modPow(x, k/2);
	tmp = (tmp * tmp) % MOD;
	if (k % 2 == 1) tmp = (tmp * x) % MOD;
	return tmp;
}

i64 modDiv(i64 a, i64 b) {
	return (a * modPow(b, MOD-2)) % MOD;
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
	int T; cin >> T;
	while (T--) {
		i64 N, M; cin >> N >> M;
		i64 ans = 0;
		vector<vector<i64>> dice;
		for (i64 i=0; i<N; i++) {
			vector<i64> tmp(6);
			for (i64 j=0; j<6; j++) cin >> tmp[j];
			dice.pub(tmp);
		}
		string mask = "", dest = "";
		for (i64 i=0; i<N/2; i++) {
			mask += "0"; dest += "5";
		}
		map<i64, i64> Map;
		while (mask <= dest) {
			i64 tmp = 1;
			//cout << "mask = " << mask << endl;
			for (i64 i=0; i<N/2; i++) {
				//cout << "chose " << dice[i][mask[i]-'0'] << endl;
				tmp = (tmp * dice[i][mask[i]-'0']) % MOD;
			}
			//cout << "tmp = " << tmp << endl;
			Map[tmp]++; mask[N/2-1]++;
			for (i64 i=N/2-1; i>0; i--) {
				if (mask[i] > '5') {
					mask[i] -= 6; mask[i-1]++;
				}
			}
		}
		mask = ""; dest = "";
		for (i64 i=N/2; i<N; i++) {
			mask += "0"; dest += "5";
		}
		i64 len = mask.size();
		while (mask <= dest) {
			i64 tmp = 1;
			//cout << "mask = " << mask << endl;
			for (i64 i=0; i<len; i++) {
				//cout << "chose " << dice[i][mask[i]-'0'] << endl;
				tmp = (tmp * dice[N/2+i][mask[i]-'0']) % MOD;
			}
			//cout << "tmp = " << tmp << endl;
			//cout << "required = " << modDiv(M, tmp) << endl;
			ans += Map[modDiv(M, tmp)];
			mask[len-1]++;
			for (i64 i=len-1; i>0; i--) {
				if (mask[i] > '5') {
					mask[i] -= 6; mask[i-1]++;
				}
			}
		}
		cout << ans << endl;
	}
	//fin.close(); fout.close();
	return 0;
}
