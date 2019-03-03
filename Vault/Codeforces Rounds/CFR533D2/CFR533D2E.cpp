#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, m; vector<string> Q;

void Input() {
	cin >> n >> m; Q.resize(n);
    for (int i=0; i<n; i++) {
        int t; cin >> t;
        if (t == 1) Q[i] = "#";
        else if (t == 2) cin >> Q[i];
    }
}

void Solve() {
	map<string, int> Map; int Max = 0, ans = 0;
    for (int i=n-1; i>=0; i--) {
        if (Q[i] == "#") {
            ans += Max; Max = 0;
            Map.clear(); continue;
        }
        Map[Q[i]]++; Max = max(Max, Map[Q[i]]);
    }
    cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/