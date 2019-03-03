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
//	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll n; cin >> n; vector<ll> a(n);
	for (ll i=0; i<n; i++) cin >> a[i];
	set<ii> Set, Ans; vector<ll> ans;
	for (ll i=0; i<n; i++) Set.insert(mp(a[i], i));
	while (Set.size() > 1) {
		auto it1 = Set.begin(), it2 = it1; it2++;
		if (it1->first != it2->first) {
			//cout << "pushed " << it1->first << "-" << it1->second << " into Ans\n";
			Ans.insert(mp(it1->second, it1->first));
			Set.erase(*it1); continue;
		}
		ii tmp = mp(it2->first, it2->second); tmp.fi *= 2;
		ii val1 = *it1, val2 = *it2;
		Set.erase(Set.find(val1)); Set.erase(Set.find(val2)); Set.insert(tmp);
		//cout << "replace " << val1.fi << "-" << val1.se << " and " << val2.fi << "-" << val2.se << " by " << tmp.fi << "-" << tmp.se << endl;
	}
	for (auto it=Set.begin(); it!=Set.end(); it++) Ans.insert(mp(it->second, it->first));
	for (auto it=Ans.begin(); it!=Ans.end(); it++) ans.push_back(it->second);
	cout << ans.size() << endl;
	for (ll i=0; i<ans.size(); i++) cout << ans[i] << " ";
	return 0;
}
