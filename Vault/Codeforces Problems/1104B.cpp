#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string s; int n;

void Input() {
	cin >> s;
	n = s.size();
}

void Solve() {
	vector<int> Prev(n, -1), Next(n, -1);
	for (int i=0; i<n-1; i++) Next[i] = i + 1;
	for (int i=1; i<n; i++) Prev[i] = i - 1;
	int ans = 0;
	for (int i=0; i >= 0 && Next[i] != -1;) {
		if (s[i] != s[Next[i]]) {i = Next[i]; continue;}
		int j = i + 1; ans++;
		while (Next[j] != -1 && Prev[i] != -1 && s[Prev[i]] == s[Next[j]]) {
			i = Prev[i]; j = Next[j]; ans++;
		}
		if (Next[j] != -1) Prev[Next[j]] = Prev[i];
		if (Prev[i] != -1) Next[Prev[i]] = Next[j];
		if (Prev[i] != -1) i = Prev[i]; else i = Next[j];
	}
	if (ans % 2 == 1) cout << "Yes\n"; else cout << "No\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
