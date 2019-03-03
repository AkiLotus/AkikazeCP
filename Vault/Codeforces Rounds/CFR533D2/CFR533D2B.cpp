#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, k; string s;

void Input() {
	cin >> n >> k >> s;
}

void Solve() {
	vector<int> cnt(26, 0);
    for (int i=0; i<n; i++) {
        int j = i;
        while (j+1 < n && s[j+1] == s[i]) j++;
        cnt[s[i]-'a'] += (j - i + 1) / k; i = j;
    }
    cout << *max_element(cnt.begin(), cnt.end()) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/