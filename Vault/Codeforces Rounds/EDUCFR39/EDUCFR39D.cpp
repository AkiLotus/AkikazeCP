/**************************************************
* Code written by Thuy-Trang Tran (thuytrang12a2) *
**************************************************/

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

typedef pair<ll, ii> iii;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll n, m, k; cin >> n >> m >> k;
	vector<vector<char>> ttable(n, vector<char>(m, '0'));
	vector<vector<ll>> classes(n);
	vector<vector<ll>> preset(n, vector<ll>(k+1, 1e18)), dp(n, vector<ll>(k+1, 1e18));
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<m; j++) {
			cin >> ttable[i][j];
			if (ttable[i][j] == '1') classes[i].push_back(j);
		}
	}
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<=k; j++) {
			if (j >= classes[i].size()) {
				preset[i][j] = 0; continue;
			}
			ll rem = classes[i].size() - j;
			for (ll x=0; x<=classes[i].size()-rem; x++) {
				preset[i][j] = min(preset[i][j], classes[i][x+rem-1] - classes[i][x] + 1);
			}
			if (preset[i][j] == 1e18) preset[i][j] = 0;
		}
	}
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<=k; j++) {
			if (i == 0) {dp[i][j] = preset[i][j]; continue;}
			for (ll x=0; x<=j; x++) dp[i][j] = min(dp[i][j], dp[i-1][j-x] + preset[i][x]);
			if (dp[i][j] == 1e18) dp[i][j] = 0;
		}
	}
//	for (ll i=0; i<n; i++) {
//		for (ll j=0; j<=k; j++) {
//			cout << preset[i][j] << " ";
//		}
//		cout << endl;
//	}
//	for (ll i=0; i<n; i++) {
//		for (ll j=0; j<=k; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << dp[n-1][k];
	return 0;
}

