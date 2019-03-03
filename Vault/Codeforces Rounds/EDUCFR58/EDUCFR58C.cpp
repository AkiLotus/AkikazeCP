#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n, l, r; vector<pair<pair<int, int>, int>> Segments;

void Input() {
	Segments.clear();
	cin >> n; Segments.resize(n);
	for (int i=0; i<n; i++) {
		cin >> l >> r;
		Segments[i] = {{l, r}, i};
	}
}

void Solve() {
	vector<int> Group(n, 1);
	sort(Segments.begin(), Segments.end());
	
	for (int i=0; i<n; i++) {
		int j = i, R = Segments[i].first.second;
		while (j+1 < n && Segments[j+1].first.first <= R) {
			R = max(R, Segments[j+1].first.second); j++;
		}
		for (int x=i; x<=j; x++) {
			int id = Segments[x].second;
			Group[id] = 2;
		}
		break;
	}
	
	if (*max_element(Group.begin(), Group.end()) == *min_element(Group.begin(), Group.end())) {cout << "-1\n"; return;}
	
	for (auto x: Group) cout << x << " "; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int q; cin >> q; while (q--) {Input(); Solve();} return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
