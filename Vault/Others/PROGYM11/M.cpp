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

// custom typedef here


// global variables here
int n, maxNode = 0;
int tree[111111];
int ans = -1;

// functions here
void ITBuild(int node, int left, int right) {
	if (right < left) return;
	maxNode = max(maxNode, node);
	if (left == right) {
		tree[node] = left;
		return;
	}
	ITBuild(node*2, left, (left+right)/2);
	ITBuild(node*2+1, (left+right)/2+1, right);
	cout << "? " << tree[node*2] << " " << tree[node*2+1] << endl; cout.flush();
	char result; cin >> result;
	if (result == '<') tree[node] = tree[node*2+1];
	else tree[node] = tree[node*2];
}

int FindRunnerUp(int node, int left, int right) {
	int p1, p2;
	if (tree[node] == tree[node*2]) {
		p1 = node*2+1;
		if (tree[node*2] == tree[node*4]) p2 = node*4+1;
		else p2 = node*4;
	}
	else if (tree[node] == tree[node*2+1]) {
		p1 = node*2;
		if (tree[node*2+1] == tree[node*4+2]) p2 = node*4+3;
		else p2 = node*4+2;
	}
	while(tree[p2*2] != 0) {
		cout << "? " << tree[p1] << " " << tree[p2] << endl; cout.flush();
		char result; cin >> result;
		if (result == '>') return tree[p1];
		else {
			p1 = p2;
			if (tree[p1] == tree[p1*2]) p2 = p1*2+1; else p2 = p1*2;
		}
	}
	cout << "? " << tree[p1] << " " << tree[p2] << endl; cout.flush();
	char result; cin >> result;
	if (result == '>') return tree[p1];
	return tree[p2];
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	// code here
	cin >> n;
	ITBuild(1, 1, n);
	ans = FindRunnerUp(1, 1, n);
	cout << "! " << ans << endl;
	return 0;
}
