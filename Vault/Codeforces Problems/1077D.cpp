#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, k; vector<int> a;
int maxcut = 0;
vector<int> cnt(200001, 0);

bool valid(int cut) {
	priority_queue<int> Q; int Rem = k;
	for (int i=0; i<200001; i++) {
		if (cnt[i] >= cut) Q.push(cnt[i]);
	}
	while (Rem > 0 && !Q.empty()) {
		int cc = Q.top(); Q.pop(); Rem--;
		cc -= cut; if (cc >= cut) Q.push(cc);
	}
	return (Rem == 0);
}

void binsearch() {
	int top = 0, bot = n;
	while (top <= bot) {
		int mid = (top + bot) / 2;
		if (valid(mid)) {
			maxcut = mid;
			top = mid + 1;
		}
		else bot = mid - 1;
	}
}

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &x: a) {
		cin >> x;
		cnt[x]++;
	}
}

void Solve() {
	binsearch();
	priority_queue<pair<int, int> > Q;
	for (int i=0; i<200001; i++) {
		if (cnt[i] < maxcut) continue;
		Q.push(make_pair(cnt[i], i));
	}
	while (k--) {
		pair<int, int> Data = Q.top(); Q.pop();
		cout << Data.second << " ";
		Data.first -= maxcut;
		if (Data.first >= maxcut) Q.push(Data);
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}