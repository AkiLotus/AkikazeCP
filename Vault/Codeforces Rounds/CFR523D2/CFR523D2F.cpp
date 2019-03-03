#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, k; set<int> Rem;

bool isCumulative(int x) {
	int Mul = k, sum = 0;
	while (sum + Mul <= x) {
		sum += Mul; Mul *= k;
	}
	return (sum == x);
}

bool try_lower(int target, int src) {
	int cnt = 0; string verdict;
	for (auto it=Rem.begin(); it!=Rem.end(); it++) {
		int z = *it; cout << "? " << src << " " << target << " " << z << endl; fflush(stdout);
		cin >> verdict; cnt += (verdict == "Yes");
	}
	return (isCumulative(cnt));
}

void DestroySubtree(int target, int src) {
	vector<int> toDestroy; string verdict;
	for (auto it=Rem.begin(); it!=Rem.end(); it++) {
		int z = *it; cout << "? " << src << " " << target << " " << z << endl; fflush(stdout);
		cin >> verdict; if (verdict == "Yes") toDestroy.push_back(z);
	}
	for (auto z: toDestroy) Rem.erase(z);
}

int Try(int x, int y) {
	if (Rem.find(x) != Rem.end()) Rem.erase(x);
	if (Rem.find(y) != Rem.end()) Rem.erase(y);
	for (auto it=Rem.begin(); it!=Rem.end(); it++) {
		int z = *it; cout << "? " << x << " " << z << " " << y << endl; fflush(stdout);
		string verdict; cin >> verdict; if (verdict == "No") continue;
		Rem.insert(x); Rem.insert(y); return Try(x, z);
	}
	bool xLower = try_lower(x, y);
	if (!xLower) swap(x, y);
	DestroySubtree(x, y);
	return y;
}

void Input() {
	cin >> n >> k;
	for (int i=1; i<=n; i++) Rem.insert(i);
}

void Solve() {
	int cur_root = Try(1, 2), Level = 0, s = 0, mul = 1;
	while (s + mul <= n) {s += mul; mul *= k; Level++;}
	if (Level == 2) {cout << "! " << cur_root; return;}
	while (!Rem.empty()) {
		cur_root = Try(cur_root, *Rem.begin());
	}
	cout << "! " << cur_root;
}

int main(int argc, char* argv[]) {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/