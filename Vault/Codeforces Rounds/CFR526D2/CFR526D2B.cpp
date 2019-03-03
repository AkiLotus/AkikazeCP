#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

long long n, s; vector<long long> v;

void Input() {
	cin >> n >> s; v.resize(n);
	for (auto &x: v) cin >> x;
}

void Solve() {
	long long sum = 0;
	for (auto x: v) sum += x;
	long long Min = *min_element(v.begin(), v.end());
	if (sum < s) {cout << "-1\n"; return;}
	long long MaximumFlat = sum - Min * n;
	long long additional = (s - MaximumFlat) / n + ((s - MaximumFlat) % n > 0);
	cout << (Min - max(additional, 0LL)) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
