#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int Mod = 1000000007;

long long modPow(int a, int b) {
	if (b == 0) return 1;
	long long tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % Mod);
	return ((((tmp * tmp) % Mod) * a) % Mod);
}

struct FenTree_Product {
	int N; vector<long long> Tree;
	FenTree_Product() {}
	FenTree_Product(int len) {Tree.clear(); N = len; Tree.resize(N+1, 1);}
	
	int LSB(int x) {
		return (x & -x);
	}
	
	void Multiply(int id, long long val) {
		id = id + 1;
		for (int i=id; i<=N; i += LSB(i)) {
			Tree[i] *= val; Tree[i] %= Mod;
		}
	}
	
	long long PrefixProduct(int id) {
		id = id + 1;
		long long ans = 1;
		for (int i=id; i > 0; i -= LSB(i)) {
			ans *= Tree[i]; ans %= Mod;
		}
		return ans;
	}
	
	long long Product(int L, int R) {
		long long RPrefix = PrefixProduct(R);
		long long LPrefix = PrefixProduct(L - 1);
		return ((RPrefix * modPow(LPrefix, Mod-2)) % Mod);
	}
};

int n, q; vector<int> a;
vector<pair<pair<int, int>, int>> Queries;
vector<long long> Result;
vector<vector<int>> AppearingID(1000001);
vector<int> AIDPointers(1000001, 0);
vector<vector<int>> Factorization(1000001);
FenTree_Product FT;

void GenerateFactorizations() {
	for (int i=2; i<1000001; i++) {
		if (!Factorization[i].empty()) continue;
		for (int j=1; j<=1000000/i; j++) {
			Factorization[i*j].push_back(i);
		}
	}
}

void Input() {
	cin >> n; a.resize(n);
	FT = FenTree_Product(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		FT.Multiply(i, a[i]);
	}
	cin >> q; Queries.resize(q); Result.resize(q);
	for (int i=0; i<q; i++) {
		cin >> Queries[i].first.first >> Queries[i].first.second;
		Queries[i].first.first--; Queries[i].first.second--;
		Queries[i].second = i;
	}
}

void Solve() {
	GenerateFactorizations();
	sort(Queries.begin(), Queries.end());
	for (int i=0; i<n; i++) {
		for (auto x: Factorization[a[i]]) {
			if (AppearingID[x].empty()) {
				FT.Multiply(i, ((x-1)*modPow(x, Mod-2)) % Mod);
			}
			AppearingID[x].push_back(i);
		}
	}
	int iter = 0;
	for (auto Q: Queries) {
		int L = Q.first.first, R = Q.first.second;
		int id = Q.second;
		while (iter < L) {
			for (auto x: Factorization[a[iter]]) {
				AIDPointers[x]++;
				FT.Multiply(iter, (x*modPow(x-1, Mod-2)) % Mod);
				if (AIDPointers[x] < AppearingID[x].size()) {
					int i = AppearingID[x][AIDPointers[x]];
					FT.Multiply(i, ((x-1)*modPow(x, Mod-2)) % Mod);
				}
			}
			iter = iter + 1;
		}
		Result[id] = FT.Product(L, R);
	}
	for (auto ans: Result) cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
