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
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// global variables here


// custom typedef here


// functions here


int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); //cin.tie(NULL);
	// code here
	vector<int> next(111111, -1);
	vector<int> prev(111111, -1);
	vector<int> toFr(111111, 0);
	vector<int> token(111111);
	int fr = -1, bk = -1;
	int n; cin >> n;
	int i=1;
	for (int a=0; a<n; a++) {
		for (int q=1; q<i; q++) if (prev[q] != -2) cout << prev[q] << " " << q << " " << next[q] << " | token = " << token[q] << endl;
		cout << "fr = " << fr << " | bk = " << bk << endl;
		char z; cin >> z;
		if (z == 'F') {
			if (bk != -1) {
				next[i] = fr; token[i] = token[fr] - 1;
			}
			else {
				token[i] = 0; bk = i;
			}
			cout << "token[" << i << "] = " << token[i] << endl;
			prev[fr] = i; fr = i; i++;
		}
		else if (z == 'B') {
			if (fr != -1) {
				prev[i] = bk; token[i] = token[bk] + 1;
			}
			else {
				token[i] = 0; fr = i;
			}
			cout << "token[" << i << "] = " << token[i] << endl;
			next[bk] = i; bk = i; i++;
		}
		else {
			int out; cin >> out;
			cout << min(token[bk]-token[out], token[out]-token[fr]) << endl;
			if (token[bk] - token[out] < token[out] - token[fr]) { // Backdoor
				int zz = token[fr], j = bk;
				while (j != out) {
					if (j == bk) token[j] = zz-1;
					else token[j] = token[next[j]] - 1;
					j = prev[j];
				}
				prev[fr] = bk; next[bk] = fr;
				fr = next[out]; bk = prev[out];
				prev[next[out]] = -1; next[prev[out]] = -1;
			}
			else { // Frontdoor
				int zz = token[bk], j = fr;
				while (j != out) {
					if (j == fr) token[j] = zz+1;
					else token[j] = token[prev[j]] + 1;
					j = next[j];
				}
				prev[fr] = bk; next[bk] = fr;
				fr = next[out]; bk = prev[out];
				prev[next[out]] = -1; next[prev[out]] = -1;
			}
			prev[out] = -2; next[out] = -2;
		}
	}
	return 0;
}
