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

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll n, k, cc = 0; string s;
	vector<ll> cnt(26, 0);
	cin >> n >> k >> s;
	for (ll i=0; i<n; i++) {
		cnt[s[i]-'a']++;
		if (cnt[s[i]-'a'] == 1) cc++;
	}
	if (*max_element(cnt.begin(), cnt.end()) > k) cout << "NO";
	else cout << "YES";
	return 0;
}

