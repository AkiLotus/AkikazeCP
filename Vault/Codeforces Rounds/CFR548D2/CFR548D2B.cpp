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

int n; vector<int> a;

long long segsum(pair<int, int> Token) {
	int L = Token.first, R = Token.second;
	int Len = R - L + 1;
	long long res = 1LL * Len * (Len - 1) / 2;
	res += (1LL * Len * L);
	return res;
}

void Input() {
	cin >> n; a.resize(n);
	for (auto &z: a) cin >> z;
}

void Solve() {
	long long ans = 0;
	vector<pair<int, int>> Stack;
	for (int i=0; i<n; i++) {
		pair<int, int> Token = {a[i], a[i]};
		while (!Stack.empty()) {
			if (Stack.back().second < Token.first - 1) break;
			if (Stack.back().second == Token.first - 1) {
				Token.first = Stack.back().first;
				ans -= segsum(Stack.back());
				Stack.pop_back(); continue;
			}
			int Len = Stack.back().second - Stack.back().first + 1;
			Token.first = max(Token.first - Len, 1);
			ans -= segsum(Stack.back()); Stack.pop_back();
		}
		Stack.push_back(Token); ans += segsum(Token);
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/