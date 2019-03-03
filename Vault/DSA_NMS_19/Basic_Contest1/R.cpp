#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int N; string S1, S2, S, S12;
map<string, bool> vis;

void Input() {
	cin >> N; if (N == 0) exit(0);
	cin >> S1 >> S2 >> S;
	S12 = ""; vis.clear();
}

void Solve() {
	for (int i=0; i<N; i++) {
		S12 += S2[i]; S12 += S1[i];
	}
	int step = 1;
	while (!vis[S12] && S12 != S) {
		vis[S12] = true;
		string newS = "";
		for (int i=0; i<N; i++) {
			newS += S12[i+N];
			newS += S12[i];
		}
		S12 = newS; step++;
	}
	
	if (S12 == S) cout << step << endl;
	else cout << "-1\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	while (true) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
