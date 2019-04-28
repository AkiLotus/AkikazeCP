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

int n; vector<pair<int, int>> A;

bool customsort1(pair<int, int> x, pair<int, int> y) {
	if (x.first != y.first) return (x.first > y.first);
	return (x.second < y.second);
}

bool customsort2(pair<int, int> x, pair<int, int> y) {
	if (x.second != y.second) return (x.second < y.second);
	return (x.first > y.first);
}

bool customsort3(pair<int, int> x, pair<int, int> y) {
	if (x.first - x.second != y.first - y.second) return (x.first - x.second > y.first - y.second);
	if (x.first != y.first) return (x.first > y.first);
	return (x.second < y.second);
}

bool customsort4(pair<int, int> x, pair<int, int> y) {
	if (x.first - x.second != y.first - y.second) return (x.first - x.second > y.first - y.second);
	if (x.second != y.second) return (x.second < y.second);
	return (x.first > y.first);
}

void Input() {
	cin >> n; A.resize(n);
	for (auto &Pair: A) cin >> Pair.first >> Pair.second;
}

void Solve() {
	sort(A.begin(), A.end(), customsort1);
	long long ans1 = 0;
	for (int i=0; i<n; i++) {
		int a = A[i].first, b = A[i].second;
		ans1 += 1LL * a * i;
		ans1 += 1LL * b * (n - 1 - i);
	}
	sort(A.begin(), A.end(), customsort2);
	long long ans2 = 0;
	for (int i=0; i<n; i++) {
		int a = A[i].first, b = A[i].second;
		ans2 += 1LL * a * i;
		ans2 += 1LL * b * (n - 1 - i);
	}
	sort(A.begin(), A.end(), customsort3);
	long long ans3 = 0;
	for (int i=0; i<n; i++) {
		int a = A[i].first, b = A[i].second;
		ans3 += 1LL * a * i;
		ans3 += 1LL * b * (n - 1 - i);
	}
	sort(A.begin(), A.end(), customsort4);
	long long ans4 = 0;
	for (int i=0; i<n; i++) {
		int a = A[i].first, b = A[i].second;
		ans4 += 1LL * a * i;
		ans4 += 1LL * b * (n - 1 - i);
	}
	cout << min({ans1, ans2, ans3, ans4}) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/