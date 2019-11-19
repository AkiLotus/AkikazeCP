#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 takethescythe
#define y1 reapyourenemies
#define yn feedontheirflesh
#define j1 ascendthroughtheirblood

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n;
int query_count = 0;
vector<int> LeftSide, RightSide;
vector<int> permutation(1, 1);

long long request(int t, int i, int j, int k) {
	if (query_count == n * 3) exit(4);
	query_count += 1;
	cout << t << " " << i << " " << j << " " << k << endl; cout.flush();
	long long response; cin >> response; return response;
}

void Input() {
	cin >> n;
}

void Solve() {
	for (int k=3; k<=n; k++) {
		long long Sign = request(2, 1, 2, k);
		if (Sign == -1) LeftSide.push_back(k);
		else RightSide.push_back(k);
	}

	// LeftSide
	if (!LeftSide.empty()) {
		vector<pair<long long, int>> Tokens;
		vector<int> LF_LeftMaxima, LF_RightMaxima;
		for (auto k: LeftSide) {
			long long area = request(1, 1, 2, k);
			Tokens.push_back({area, k});
		}
		sort(Tokens.begin(), Tokens.end());
		int maxima = Tokens.back().second;
		for (int i=0; i<Tokens.size()-1; i++) {
			int k = Tokens[i].second;
			long long Sign = request(2, 1, maxima, k);
			if (Sign == -1) LF_LeftMaxima.push_back(k);
			else LF_RightMaxima.push_back(k);
		}
		reverse(LF_RightMaxima.begin(), LF_RightMaxima.end());
		for (auto z: LF_LeftMaxima) permutation.push_back(z);
		permutation.push_back(maxima);
		for (auto z: LF_RightMaxima) permutation.push_back(z);
	}

	permutation.push_back(2);

	// RightSide
	if (!RightSide.empty()) {
		vector<pair<long long, int>> Tokens;
		vector<int> RG_LeftMaxima, RG_RightMaxima;
		for (auto k: RightSide) {
			long long area = request(1, 1, 2, k);
			Tokens.push_back({area, k});
		}
		sort(Tokens.begin(), Tokens.end());
		int maxima = Tokens.back().second;
		for (int i=0; i<Tokens.size()-1; i++) {
			int k = Tokens[i].second;
			long long Sign = request(2, 1, maxima, k);
			if (Sign == -1) RG_LeftMaxima.push_back(k);
			else RG_RightMaxima.push_back(k);
		}
		reverse(RG_RightMaxima.begin(), RG_RightMaxima.end());
		for (auto z: RG_LeftMaxima) permutation.push_back(z);
		permutation.push_back(maxima);
		for (auto z: RG_RightMaxima) permutation.push_back(z);
	}

	cout << "0";
	for (auto z: permutation) cout << " " << z;
	cout << endl; cout.flush();
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/