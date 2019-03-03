#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, q; vector<string> A; vector<int> cnt;
map<string, int> ID; string a, b; vector<vector<int>> Table;

int Manacher_Sum(string &s) {
	int res = 0, N = s.size();
	vector<int> odd(N, 0), even(N, 0);
	for (int i=0, l=0, r=-1; i<N; i++) {
		int k = 0; if (i <= r) k = min(odd[l+r-i], r-i);
		while (0 <= i-k-1 && i+k+1 < N && s[i-k-1] == s[i+k+1]) k++;
		odd[i] = k + 1; res += odd[i];
		if (i + k > r) {l = i - k; r = i + k;}
	}
	for (int i=1, l=0, r=-1; i<N; i++) {
		if (s[i-1] != s[i]) continue;
		int k = 0; if (i <= r) k = min(odd[l+r-i+1], r-i);
		while (0 <= (i-1)-k-1 && i+k+1 < N && s[(i-1)-k-1] == s[i+k+1]) k++;
		even[i] = k + 1; res += even[i];
		if (i + k > r) {l = (i-1) - k; r = i + k;}
	}
	return res;
}

void ProcessTable() {
	Table.resize(n);
	for (int i=0; i<n; i++) Table[i].push_back(i);
	for (int j=1; j<16; j++) {
		for (int i=0; i<n; i++) {
			if (i + (1LL << j) > n) continue;
			int id1 = Table[i][j-1], id2 = Table[i+(1LL<<(j-1))][j-1];
			if (cnt[id1] > cnt[id2]) Table[i].push_back(id1);
			else if (cnt[id1] < cnt[id2]) Table[i].push_back(id2);
			else Table[i].push_back(min(id1, id2));
		}
	}
}

int GetIDMax(int L, int R) {
	int pos = log2(R - L + 1);
	int id1 = Table[L][pos], id2 = Table[R-(1LL<<pos)+1][pos];
	if (cnt[id1] > cnt[id2]) return id1;
	else if (cnt[id2] > cnt[id1]) return id2;
	else return min(id1, id2);
}

void Input() {
	scanf("%d%d", &n, &q);
	A.clear(); cnt.clear(); Table.clear();
	A.resize(n); cnt.resize(n);
	for (int i=0; i<n; i++) {
		scanf("%s", A[i]); ID[A[i]] = i;
	}
}

void Solve() {
	for (int i=0; i<n; i++) {
		cnt[i] = Manacher_Sum(A[i]);
	}
	ProcessTable();
	while (q--) {
		scanf("%s%s", a, b);
		int L = ID[a], R = ID[b];
		printf("%d\n", GetIDMax(L, R) + 1);
	}
}

int main(int argc, char* argv[]) {
	int T; cin >> T;
	while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/