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
	ll n, ans = 0; vector<ll> B, R, P; cin >> n;
	for (ll i=0; i<n; i++) {
		ll x; char c; cin >> x >> c;
		if (c == 'B') B.push_back(x);
		else if (c == 'R') R.push_back(x);
		else if (c == 'P') P.push_back(x);
	}
	if (!P.empty()) ans += (P[P.size()-1] - P[0]);
	else {
		if (!B.empty()) ans += (B[B.size()-1] - B[0]);
		if (!R.empty()) ans += (R[R.size()-1] - R[0]);
		cout << ans; return 0;
	}
	for (ll i=0; i<B.size(); i++) {
		if (B[i] < P[0]) {
			if (i == 0) ans += (P[0] - B[i]);
		}
		else if (B[i] < P[P.size()-1]) {
			ll x = lower_bound(P.begin(), P.end(), B[i]) - P.begin();
			if (i == 0) ans += min(B[i] - P[x-1], P[x] - B[i]);
			else ans += min(min(B[i] - P[x-1], P[x] - B[i]), B[i] - B[i-1]);
		}
		else {
			ans += (B[B.size()-1] - P[P.size()-1]);
			break;
		}
	}
	for (ll i=0; i<R.size(); i++) {
		if (R[i] < P[0]) {
			if (i == 0) ans += (P[0] - R[i]);
		}
		else if (R[i] < P[P.size()-1]) {
			ll x = lower_bound(P.begin(), P.end(), R[i]) - P.begin();
			if (i == 0) ans += min(R[i] - P[x-1], P[x] - R[i]);
			else ans += min(min(R[i] - P[x-1], P[x] - R[i]), R[i] - R[i-1]);
		}
		else {
			ans += (R[R.size()-1] - P[P.size()-1]);
			break;
		}
	}
	cout << ans;
	return 0;
}
