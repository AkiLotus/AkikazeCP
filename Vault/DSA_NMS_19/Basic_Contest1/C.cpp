#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int L, R; vector<int> A;
vector<int> Valid;
int Hash[] = {2, 3, 5, 7};

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i=2; i<=sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

void Prepare(int Len) {
	vector<int> Mask(Len, 0);
	do {
		int sum = 0, val = 0;
		for (int i=0; i<Len; i++) {
			sum += Hash[Mask[i]]; val *= 10;
			val += Hash[Mask[i]];
		}
		if (isPrime(sum) && isPrime(val)) Valid.push_back(val);
		int ite = Len-1; Mask[ite]++;
		while (ite > 0) {
			while (Mask[ite] > 3) {Mask[ite] -= 4; Mask[ite-1]++;}
			ite = ite - 1;
		}
	} while (Mask[0] < 4);
}

void Input() {
	cin >> L >> R;
}

void Solve() {
	int x = lower_bound(Valid.begin(), Valid.end(), L) - Valid.begin();
	int y = upper_bound(Valid.begin(), Valid.end(), R) - Valid.begin();
	cout << (y - x) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	for (int i=1; i<10; i++) Prepare(i); sort(Valid.begin(), Valid.end());
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
  *  #Team4T Primary Flagship - Salvation  *
  \******************************************/
