#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int n, Max = -1000000000, d = 0;
int queryRemaining = 60; vector<int> id;

void findMax() {
	int top = -1000000000, bot = +1000000000;
	while (top <= bot) {
		int hasHigher;
		int mid = (top + bot) / 2;
		cout << "> " << mid << endl;
		fflush(stdout); cin >> hasHigher;
		queryRemaining--;
		if (hasHigher) top = mid + 1;
		else {bot = mid - 1; Max = mid;}
	}
}

void findD() {
	vector<int> List; int RandomRange = n;
	while (queryRemaining > 0 && RandomRange > 0) {
		int demandedIndex = rng32() % RandomRange;
		cout << "? " << id[demandedIndex] << endl; fflush(stdout);
		int z; cin >> z; List.push_back(z);
		RandomRange--; queryRemaining--;
		swap(id[demandedIndex], id[RandomRange]);
	}
	sort(List.begin(), List.end());
	if (List.back() != Max) List.push_back(Max);
	for (int i=1; i<List.size(); i++) {
		d = __gcd(d, List[i] - List[i-1]);
	}
}

void Input() {
	cin >> n; id.resize(n);
	for (int i=0; i<n; i++) id[i] = i+1;
}

void Solve() {
	findMax(); findD();
	int Min = Max - d * (n - 1);
	cout << "! " << Min << " " << d;
	cout << endl; fflush(stdout);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}
