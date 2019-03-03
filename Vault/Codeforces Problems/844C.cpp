/**************************************************
* Code written by Thuy-Trang Tran (thuytrang12a2) *
**************************************************/

#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
using namespace std;

vector<vector<ll>> ans;
vector<ll> q;
vector<bool> visited(100008, false);
vector<vector<ll>> adj(100008, vector<ll>(0));

void DFS(ll z) {
	visited[z] = true;
	q.push_back(z);
	for (ll i=0; i<adj[z].size(); i++) {
		if (!visited[adj[z][i]]) DFS(adj[z][i]);
	}
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll n; cin >> n;
	vector<ii> a(n);
	for (ll i=0; i<n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a.begin(), a.end());
	for (ll i=0; i<n; i++) {
		if (a[i].se != i) {
			adj[a[i].se].push_back(i);
			adj[i].push_back(a[i].se);
		}
	}
	for (ll i=0; i<n; i++) {
		q.clear();
		if (!visited[i]) {
			DFS(i);
			ans.push_back(q);
		}
	}
	cout << ans.size() << endl;
	for (ll i=0; i<ans.size(); i++) {
		cout << ans[i].size();
		for (ll j=0; j<ans[i].size(); j++) cout << " " << ans[i][j] + 1;
		cout << endl;
	}
	return 0;
}

