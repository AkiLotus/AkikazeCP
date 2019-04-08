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

int n, q; vector<long long> s, l, r;

void Input() {
	cin >> n; s.resize(n);
	for (auto &z: s) cin >> z;
	cin >> q; l.resize(q); r.resize(q);
	for (int i=0; i<q; i++) cin >> l[i] >> r[i];
}

void Solve() {
	vector<pair<long long, int>> RangeList;
	vector<long long> res(q); set<pair<long long, long long>> Set;
	for (int i=0; i<n; i++) Set.insert({s[i], s[i]});
	set<pair<long long, pair<long long, long long>>> Heap;
	for (auto it=Set.begin(); ; it++) {
		auto it1 = it; it1++;
		if (it1 == Set.end()) break;
		pair<long long, long long> a1 = *it, a2 = *it1;
		Heap.insert({a2.first - a1.second, a1});
	}
	for (int i=0; i<q; i++) RangeList.push_back({r[i] - l[i], i});
	long long cont = Set.size();
	sort(RangeList.begin(), RangeList.end());
	for (auto Query: RangeList) {
		long long ran = Query.first; int id = Query.second;
		while (!Heap.empty() && Heap.begin()->first <= ran) {
			pair<long long, pair<long long, long long>> Token = *Heap.begin();
			Heap.erase(Token);
			pair<long long, long long> st = Token.second;
			long long diff = Token.first;
			pair<long long, long long> en = *Set.lower_bound({st.second+diff, LLONG_MIN});
			Set.erase(st); Set.erase(en);
			cont -= (st.second - st.first + 1);
			cont -= (en.second - en.first + 1);
			if (Set.upper_bound(en) != Set.end()) {
				pair<long long, long long> en2 = *Set.upper_bound(en);
				Heap.erase({en2.first - en.second, en});
			}
			Set.insert({st.first, en.second});
			cont += (en.second - st.first + 1);
			if (Set.upper_bound({st.first, en.second}) != Set.end()) {
				pair<long long, long long> p1 = make_pair(st.first, en.second);
				pair<long long, long long> p2 = *Set.upper_bound({st.first, en.second});
				Heap.insert({p2.first - p1.second, p1});
			}
		}
		res[id] = Set.size() * ran + cont;
	}
	for (auto z: res) cout << z << " "; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/