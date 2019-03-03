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
int n, k, tmp = 0;
int level[1111111];
int tree[1111111];
vector<int> ans(n, 0);

// custom typedef here


// functions here
void ITtree_Build(int N, int L, int R) {
	if (R < L) return;
	if (N != 1) level[N] = level[N/2] + 1;
	//cout << "level[" << N << "] = " << level[N] << endl;
	if (L == R) {
		tree[N] = true; return;
	}
	ITtree_Build(N*2, L, (L+R)/2);
	ITtree_Build(N*2+1, (L+R)/2+1, R);
	tree[N] = true;
}

void DFS(int z, int L, int R) {
	if (tmp == k) return;
	if (L == R) {
		tmp++; return;
	}
	//cout << "False at segment " << L << " " << R << endl;
	tree[z] = false; tmp++;
	DFS(2*z, L, (L+R)/2);
	if (tmp == k) return;
	DFS(2*z+1, (L+R)/2+1, R);
}

void Analyze(int N, int L, int R) {
	//cout << "Working at segment " << L << " " << R << endl;
	if ((level[N] % 2 == 0 && !tree[N]) || (level[N] % 2 == 1 && tree[N])) {
		reverse(ans.begin()+L, ans.begin()+R);
		//cout << "Reversing segment " << L << " " << R << endl;
	}
	if (L == R || tree[N]) return;
	Analyze(2*N, L, (L+R)/2);
	Analyze(2*N+1, (L+R)/2, R);
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	cin >> n >> k;
	ITtree_Build(1, 0, n);
	if (k % 2 == 0) {
		cout << "-1"; return 0;
	}
	ans.resize(n,0);
	for (int i=0; i<n; i++) ans[i] = i+1;
	if (k != 1) {
		DFS(1, 0, n);
		Analyze(1, 0, n);
	}
	for (int i=0; i<n; i++) cout << ans[i] << " ";
	return 0;
}
