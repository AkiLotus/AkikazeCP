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

ll n, m;
bool cycle = false;
ll core = -1, fuse = -1;
vector<ll> visited(1000, 0);
vector<ll> previous(1000, -1);
vector<vector<ll>> mat(1000, vector<ll>(1000, 0));

void DFS(ll z) {
	visited[z] = 2;
	for (ll i=1; i<=n; i++) {
		if (!mat[z][i]) continue;
		if (!visited[i]) {
			previous[i] = z; DFS(i);
		}
		else if (visited[i] == 2) {
			if (core == -1) {core = i; fuse = z;}
			cycle = true;
		}
		if (cycle) return;
	}
	visited[z] = 1;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	for (ll i=0; i<m; i++) {
		ll x, y; cin >> x >> y;
		mat[x][y] = 1;
	}
	for (ll i=1; i<=n; i++) {
		if (cycle) break;
		for (ll j=1; j<=n; j++) {
			if (visited[j] == 2) visited[j] = 1;
		}
		if (!visited[i]) {
			previous[i] = -1; DFS(i);
		}
	}
	if (core == -1) {
		cout << "YES"; return 0;
	}
	ll tmp = fuse;
	while (previous[tmp] != -1) {
		ll tmp1 = previous[tmp];
		mat[tmp1][tmp] = 0;
		cycle = false;
		for (ll i=1; i<=n; i++) visited[i] = 0;
		for (ll i=1; i<=n; i++) {
			if (cycle) break;
			for (ll j=1; j<=n; j++) {
				if (visited[j] == 2) visited[j] = 1;
			}
			if (!visited[i]) {
				previous[i] = -1; DFS(i);
			}
		}
		if (!cycle) {
			cout << "YES"; return 0;
		}
		mat[tmp1][tmp] = 1;
		tmp = tmp1;
	}
	mat[fuse][core] = 0;
	cycle = false;
	for (ll i=1; i<=n; i++) visited[i] = 0;
	for (ll i=1; i<=n; i++) {
		if (cycle) break;
		for (ll j=1; j<=n; j++) {
			if (visited[j] == 2) visited[j] = 1;
		}
		if (!visited[i]) {
			previous[i] = -1; DFS(i);
		}
	}
	if (!cycle) {
		cout << "YES";
	}
	else cout << "NO";
	return 0;
}

