#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long Mod = 998244353LL;

long long modPow(long long a, int b) {
	if (b == 0) return 1;
	long long tmp = modPow(a, b/2);
	if (b % 2 == 0) return ((tmp * tmp) % Mod);
	return ((((tmp * tmp) % Mod) * a) % Mod);
}

int n, k, len; vector<int> a;

void Input() {
	cin >> n >> k >> len; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	int hidden = 0, left = 0, right = 0;
	for (auto x: a) right += (x == -1);
	long long ans = modPow(right, k);
	multiset<int> MS;
	for (int i=0; i<len-1; i++) {
		if (a[i] == -1) {hidden++; right--;}
		else MS.insert(a[i]);
	}
	for (int i=len-1; i<n; i++) {
		if (a[i] == -1) {hidden++; right--;}
		else MS.insert(a[i]);
		
		long long tmp = (modPow(max(0, left), k) * modPow(max(0, right-1), k)) % Mod;
		tmp *= (k - 1); tmp %= Mod;
		if (MS.size() > 1) tmp *= 0; else if (MS.empty()) tmp *= k; tmp %= Mod;
		
		ans -= tmp; ans %= Mod; while (ans < 0) ans += Mod;
		
		if (a[i-len+1] == -1) {hidden--; left++;}
		else MS.erase(MS.find(a[i]));
	}
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
