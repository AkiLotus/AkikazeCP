#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define endl '\n'

int test = 0;
int l, r, n;
vector<pair<i64, i64>> Impurities;

i64 TrueLength(i64 st, i64 en, i64 key = -1) {
	if (key != -1) {
		st = max(st, l - key);
		en = min(r + key, en);
	}
	i64 MaximumAllowed = ((st < l) ? ((en - l) * 2) : ((r - st) * 2));
	if (st < l && r < en) MaximumAllowed = (r - l) * 2;
	tracker4(st, en, key, MaximumAllowed);
	return min(en - st, MaximumAllowed);
}

void Input() {
	cin >> l >> r >> n; Impurities.clear(); Impurities.resize(n);
	for (auto &P: Impurities) cin >> P.first >> P.second;
}

void Solve() {
	map<i64, vector<i64>> Map;
	for (auto &P: Impurities) {
		int x = P.first, y = P.second;
		Map[abs(y)].push_back(x);
	}

	i64 ans = 0;
	set<pair<i64, i64>> Segment, CornerSegment;
	multiset<i64> Segment_TrueLength;
	CornerSegment.insert({-1000000000000LL, +1000000000000LL});
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		i64 y = it->first;

		if (!Segment_TrueLength.empty()) ans = max(ans, min(*Segment_TrueLength.rbegin(), y));
		for (auto it: CornerSegment) {
			i64 x_1 = it.first, x_2 = it.second;
			ans = max(ans, min(TrueLength(x_1, x_2, y), y));
		}

		for (auto x: Map[y]) {
			bool exist_inMain = false;
			auto ptr1 = Segment.lower_bound({x+1, 0});
			if (ptr1 != Segment.begin()) {
				exist_inMain = true;
				ptr1--;
				i64 x_1 = ptr1->first, x_2 = ptr1->second;
				Segment_TrueLength.erase(Segment_TrueLength.find(x_2 - x_1));
				Segment.erase({x_1, x_2});
				Segment_TrueLength.insert(x_2 - x);
				Segment_TrueLength.insert(x - x_1);
				Segment.insert({x_1, x});
				Segment.insert({x, x_2});
			}
			else {
				auto ptr1 = CornerSegment.lower_bound({x+1, 0});
				if (ptr1 != CornerSegment.begin()) {
					ptr1--;
					i64 x_1 = ptr1->first, x_2 = ptr1->second;
					//cout << "Hurrah: "; tracker3(x_1, x, x_2);
					CornerSegment.erase({x_1, x_2});
					if ((x_1 < l && x > l) || (x_1 < r && x > r)) CornerSegment.insert({x_1, x});
					else if (x_1 >= l && x <= r) {
						Segment.insert({x_1, x});
						Segment_TrueLength.insert(x - x_1);
					}
					if ((x < l && x_2 > l) || (x < r && x_2 > r)) CornerSegment.insert({x, x_2});
					else if (x >= l && x_2 <= r) {
						Segment.insert({x, x_2});
						Segment_TrueLength.insert(x_2 - x);
					}
				}
			}
			//tracker4(x, y, Segment, CornerSegment);
		}
		//tracker2(y, ans);
	}
	if (!Segment_TrueLength.empty()) ans = max(ans, *Segment_TrueLength.rbegin());
	for (auto it: CornerSegment) {
		i64 x_1 = it.first, x_2 = it.second;
		ans = max(ans, TrueLength(x_1, x_2));
	}
	
	cout << "Case #" << (++test) << endl;
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}