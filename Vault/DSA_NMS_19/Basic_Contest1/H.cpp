#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n;

void Input() {
	cin >> n;
}

void Solve() {
	int ans = 0;
	
	ans += n / 1000; n %= 1000;
	ans += n / 500; n %= 500;
	ans += n / 200; n %= 200;
	ans += n / 100; n %= 100;
	ans += n / 50; n %= 50;
	ans += n / 20; n %= 20;
	ans += n / 10; n %= 10;
	ans += n / 5; n %= 5;
	ans += n / 2; n %= 2;
	ans += n / 1; n %= 1;
	
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
