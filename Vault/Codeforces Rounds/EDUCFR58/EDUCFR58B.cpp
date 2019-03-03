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
	int l = 0, r = n-1;
	while (l < n && s[l] != '[') l++;
	while (l < n && s[l] != ':') l++;
	while (r >= 0 && s[r] != ']') r--;
	while (r >= 0 && s[r] != ':') r--;
	if (l >= n || r < 0) {cout << "-1\n"; return;}
	if (l >= r) {cout << "-1\n"; return;}
	int ans = 4;
	for (int x=l; x<=r; x++) ans += (s[x] == '|');
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
