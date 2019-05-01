#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

vector<long long> a(3);
vector<long long> choice(7, 0);

long long binsearch(long long L, long long R, long long start) {
	long long res = L;
	while (L <= R) {
		long long mid = (L + R) / 2;
		vector<long long> Z(3, 0);
		long long tmp = mid;
		if (start > 0) {
			for (long long x=start; (x<7 && tmp > 0); x++) {
				Z[choice[x]]++; tmp--;
			}
		}
		Z[0] += (tmp / 7) * 3;
		Z[1] += (tmp / 7) * 2;
		Z[2] += (tmp / 7) * 2;
		tmp %= 7;
		for (long long x=0; x<tmp; x++) Z[choice[x]]++;
		if (a[0] < Z[0] || a[1] < Z[1] || a[2] < Z[2]) {R = mid - 1;}
		else {res = mid; L = mid + 1;}
	}
	return res;
}

void Input() {
	for (auto &z: a) cin >> z;
	choice[1] = choice[5] = 1;
	choice[2] = choice[4] = 2;
}

void Solve() {
	long long Max = LLONG_MIN;
	for (long long x=0; x<7; x++) {
		Max = max(Max, binsearch(0LL, a[0]+a[1]+a[2], x));
	}
	cout << Max << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/