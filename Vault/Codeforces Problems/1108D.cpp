#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; string s;

void Input() {
	cin >> n >> s;
}

void Solve() {
	int step = 0;
	for (int i=0; i<n; i++) {
		int j = i, Len = 1;
		while (j+1 < n && s[j+1] == s[i]) {j++; Len++;}
		char chosen = '\0';
		if (s[i] == 'R') {
			chosen = 'G';
			if (Len % 2 == 0 && j+1 < n && s[j+1] == 'G') chosen = 'B';
		}
		if (s[i] == 'G') {
			chosen = 'R';
			if (Len % 2 == 0 && j+1 < n && s[j+1] == 'R') chosen = 'B';
		}
		if (s[i] == 'B') {
			chosen = 'G';
			if (Len % 2 == 0 && j+1 < n && s[j+1] == 'G') chosen = 'R';
		}
		step += Len / 2;
		for (int x=1; x<Len; x+=2) s[i+x] = chosen;
		i = j;
	}
	cout << step << endl << s << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
