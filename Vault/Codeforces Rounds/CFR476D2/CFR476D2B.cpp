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
	ll n, k; cin >> n >> k;
	vector<vector<char>> board(n, vector<char>(n, '.'));
	vector<vector<ll>> cnt(n, vector<ll>(n, 0));
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<n; j++) {
			cin >> board[i][j];
		}
	}
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<=n-k; j++) {
			bool flag = true;
			for (ll x=j; x<j+k; x++) {
				if (board[i][x] != '.') {
					flag = false; break;
				}
			}
			if (!flag) continue;
			for (ll x=j; x<j+k; x++) {
				cnt[i][x]++;
			}
		}
	}
	for (ll i=0; i<=n-k; i++) {
		for (ll j=0; j<n; j++) {
			bool flag = true;
			for (ll x=i; x<i+k; x++) {
				if (board[x][j] != '.') {
					flag = false; break;
				}
			}
			if (!flag) continue;
			for (ll x=i; x<i+k; x++) {
				cnt[x][j]++;
			}
		}
	}
	ll mxX = 0, mxY = 0;
	for (ll i=0; i<n; i++) {
		for (ll j=0; j<n; j++) {
			if (cnt[i][j] > cnt[mxX][mxY]) {
				mxX = i; mxY = j;
			}
		}
	}
	cout << mxX + 1 << " " << mxY + 1;
	return 0;
}