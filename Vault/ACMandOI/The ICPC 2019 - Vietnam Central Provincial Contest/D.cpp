/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: D.cpp
// Time created: Sun Oct 06 2019 01:05

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
vector<bool> isPrime(1000001, true);
int n; vector<int> a;
/************************************************/

/************** [FUNCTIONS] **************/
template <class DataType> struct node {
	DataType value, lazy;
	node() {value = 0; lazy = 0;}
	node(DataType x) {value = x; lazy = 0;}
};

template <class DataType> class segtree {
private:
	int size; vector<node<DataType>> Tree;
	
	// modify these data to suit your segment tree requirements
	// default value
	const int DefaultValue = 0;
	// release lazy attributes
	void releaseLazy(node<DataType> &Node) {
		Node.value += Node.lazy;
		Node.lazy = 0;
	}
	// update lazy attributes
	void updateLazy(node<DataType> &Node, DataType d) {
		Node.lazy += d;
	}
	// merge two children nodes
	DataType merge(DataType x, DataType y) {
		return (x + y);
	}
	
	void propagate(int node, int st, int en) {
		if (Tree[node].lazy == 0) return;
		if (st != en) {
			updateLazy(Tree[node*2+1], Tree[node].lazy);
			updateLazy(Tree[node*2+2], Tree[node].lazy);
		}
		releaseLazy(Tree[node]);
	}
	void update(int node, int st, int en, int L, int R, DataType d) {
		propagate(node, st, en);
		if (en < L || R < st) return;
		if (L <= st && en <= R) {updateLazy(Tree[node], d); propagate(node, st, en); return;}
		update(node*2+1, st, (st+en)/2+0, L, R, d);
		update(node*2+2, (st+en)/2+1, en, L, R, d);
		Tree[node].value = merge(Tree[node*2+1].value, Tree[node*2+2].value);
	}
	DataType calc(int node, int st, int en, int L, int R) {
		if (en < L || R < st) return 0LL;
		if (L <= st && en <= R) return Tree[node].value;
		DataType p1 = calc(node*2+1, st, (st+en)/2+0, L, R);
		DataType p2 = calc(node*2+2, (st+en)/2+1, en, L, R);
		return merge(p1, p2);
	}
public:
	segtree(int N) {
		size = N; Tree.resize(N*4);
	}
	segtree(int N, vector<DataType> &A) {
		size = N; Tree.resize(N*4, node<DataType>(DefaultValue));
		for (int i=0; i<N; i++) update(0, 0, N-1, i, i, A[i]);
	}
	DataType getRange(int L, int R) {
		return calc(0, 0, size-1, L, R);
	}
	DataType get(int id) {
		return getRange(id, id);
	}
	void updateRange(int L, int R, DataType d) {
		update(0, 0, size-1, L, R, d);
	}
	void update(int id, DataType d) {
		updateRange(id, id, d);
	}
};

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	isPrime[0] = isPrime[1] = false;
	for (int i=2; i<1000001; i++) {
		if (!isPrime[i]) continue;
		for (int j=i; j<=1000000/i; j++) {
			isPrime[i*j] = false;
		}
	}
	vector<int> primeOverComposite(n+1, 1);
	int offset = n; i64 ans = 0;
	segtree<int> ST = segtree<int>(2*n+1);
	if (!isPrime[a[0]]) primeOverComposite[0] = 0;
	ST.update(offset, 1);
	for (int i=1; i<=n; i++) {
		primeOverComposite[i] = primeOverComposite[i-1];
		if (!isPrime[a[i-1]]) primeOverComposite[i]--;
		else primeOverComposite[i]++;
		ans += ST.getRange(0, offset+primeOverComposite[i]);
		ST.update(offset+primeOverComposite[i], 1);
	}
	cout << ans << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifndef Akikaze
		if (OImode) {
			assert(freopen(infile, "r", stdin));
			assert(freopen(outfile, "w", stdout));
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/