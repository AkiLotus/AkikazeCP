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

int n; string s1, s2;

void Input() {
	cin >> n >> s1 >> s2;
}

void Solve() {
	vector<pair<int, int>> PairList;
	vector<int> q1, q2; vector<vector<int>> cl1(26), cl2(26);
	set<int> avail1, avail2;
	for (int i=0; i<n; i++) {
		if (s1[i] == '?') q1.push_back(i+1);
		else {avail1.insert(i+1); cl1[s1[i]-'a'].push_back(i+1);}
		if (s2[i] == '?') q2.push_back(i+1);
		else {avail2.insert(i+1); cl2[s2[i]-'a'].push_back(i+1);}
	}
	for (int i=0; i<26; i++) {
		int Len = min(cl1[i].size(), cl2[i].size());
		for (int x=0; x<Len; x++) {
			int id1 = cl1[i].back(), id2 = cl2[i].back();
			cl1[i].pop_back(); cl2[i].pop_back();
			avail1.erase(id1); avail2.erase(id2);
			PairList.push_back({id1, id2});
		}
	}
	while (!q1.empty() && !avail2.empty()) {
		int id1 = q1.back(), id2 = *avail2.begin();
		q1.pop_back(); avail2.erase(id2);
		PairList.push_back({id1, id2});
	}
	while (!avail1.empty() && !q2.empty()) {
		int id1 = *avail1.begin(), id2 = q2.back();
		avail1.erase(id1); q2.pop_back();
		PairList.push_back({id1, id2});
	}
	while (!q1.empty() && !q2.empty()) {
		int id1 = q1.back(), id2 = q2.back();
		q1.pop_back(); q2.pop_back();
		PairList.push_back({id1, id2});
	}
	cout << PairList.size() << endl;
	for (auto P: PairList) cout << P.first << " " << P.second << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/