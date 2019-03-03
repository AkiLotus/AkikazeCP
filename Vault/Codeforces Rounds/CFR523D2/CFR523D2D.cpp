#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long Mod = 1000000007LL;

int n; long long x, y;
long long ans = 0;
vector<pair<long long, long long>> shows;

void Input() {
	cin >> n >> x >> y; shows.resize(n);
	for (auto &z: shows) {
		cin >> z.first >> z.second;
		ans += (z.second - z.first) * y + x;
		ans %= Mod;
	}
}

void Solve() {
	sort(shows.begin(), shows.end());
	multiset<long long> RightEnds;
	for (int i=0; i<n; i++) {
		long long L = shows[i].first;
		long long R = shows[i].second;
		if (RightEnds.upper_bound(-L) == RightEnds.end()) {
			RightEnds.insert(-R); continue;
		}
		long long ClosesttoLeft = -(*RightEnds.upper_bound(-L));
		if (y * (L - ClosesttoLeft) >= x) {RightEnds.insert(-R); continue;}
		ans += (y * (L - ClosesttoLeft)) % Mod; ans %= Mod;
		ans -= x; ans %= Mod; while (ans < 0) ans += Mod;
		RightEnds.erase(RightEnds.find(-ClosesttoLeft)); RightEnds.insert(-R);
	}
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/