// Code written by JadeMasochist

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
using namespace std;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll N, node = 1, ans = 0; 
	vector<vector<ll>> mask(1, vector<ll>(26, -1));
	vector<ll> parent(1, -1); vector<bool> hasToken(false);
	cin >> N; vector<string> vars(N);
	for (ll i=0; i<N; i++) {cin >> vars[i]; ans += vars[i].size();}
	cout << vars << endl;
	priority_queue<ii> heap;
	for (ll z=0; z<N; z++) {
		ll position = 0;
		for (ll i=0; i<vars[z].size(); i++) {
			if (mask[position][vars[z][i]-'a'] != -1) {
				//cout << "following old trail to node " << mask[position][s[i]-'a'] << endl;
				position = mask[position][vars[z][i]-'a'];
			}
			else {
				mask.push_back(vector<ll>(26, -1));
				parent.push_back(position); hasToken.push_back(false);
				mask[position][vars[z][i]-'a'] = node++;
				position = node - 1;
				//cout << "new trail to node " << node-1 << endl;
			}
		}
		heap.push(mp(vars[z].size(), position));
		hasToken[position] = true;
	}
	while (!heap.empty()) {
		ii z = heap.top(); heap.pop();
		if (parent[z.se] == 0) continue;
		tracker1(z);
		bool flag = true;
		for (ll i=0; i<26; i++) {
			if (mask[parent[z.se]][i] == -1) continue;
			if (mask[parent[z.se]][i] == z.se) continue;
			if (hasToken[mask[parent[z.se]][i]]) {
				flag = false; break;
			}
		}
		if (flag) {
			hasToken[z.se] = false; ans--;
			hasToken[parent[z.se]] = true;
			heap.push(mp(z.fi-1, parent[z.se]));
		}
	}
	cout << ans;
	return 0;
}