#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

long long t, n, k, ans;

long long sqr(long long x) {
	return (x * x);
}

long long pow2(long long x) {
	if (x == 0) return 1;
	long long tmp = pow2(x / 2);	
	if (x % 2 == 0) return (tmp * tmp);
	return (tmp * tmp * 2);
}

long long minimumMoves(long long x) {
	long long dist = n - x, res = 0, Mul = 1;
	if (dist > 61) return 4000000000000000000LL;
	for (long long i=1; i<=dist; i++) {
		res += Mul; Mul *= 2; Mul++;
	}
	return res;
}

long long maximumMoves(long long x) {
	if (x > 32) return 8000000000000000000LL;
	long long res = minimumMoves(x);
	long long dist = n - x, Mul = 1;
	if (dist > 32) return (8000000000000000000LL);
	for (long long i=0; i<dist; i++) {
		res += sqr(pow2(i)-1);
	}
	long long cnt = sqr(pow2(n-x)-1);
	for (long long i=x; i>0; i--) {
		res += cnt;
		if (1000000000000000000LL <= cnt) cnt = 4000000000000000000LL;
		else cnt *= 4;
		if (res > 4000000000000000000LL) return 8000000000000000000LL;
	}
	return res;
}

void binsearch() {
	long long top = max(0LL, n-61), bot = n;
	for (long long mid = top; mid <= bot; mid++) {
		long long Min = minimumMoves(mid);
		long long Max = maximumMoves(mid);
		if (Min <= k && k <= Max) {ans = mid; return;}
	}
}

void Input() {
	cin >> t;
}

void Solve() {
	while (t--) {
		cin >> n >> k; ans = -1; binsearch();
		if (ans == -1) cout << "NO\n";
		else cout << "YES " << ans << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/