#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<int> a;
vector<int> diffcnt(100001, 0);

void Input() {
	cin >> n >> m; a.resize(m);
	for (auto &z: a) cin >> z;
}

void Solve() {
	int contest = 1, Rem = n;
	for (int i=0; i<m; i++) {
		diffcnt[a[i]]++;
		if (diffcnt[a[i]] == contest) Rem--;
		if (Rem > 0) cout << "0";
		else {
			cout << "1"; contest++;
			for (int x=1; x<=n; x++) {
				Rem += (diffcnt[x] < contest);
			}
		}
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
