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
	string s; ll k;
	cin >> s >> k;
	vector<ll> cc(26, 0); ll cnt = 0;
	for (ll i=0; i<s.size(); i++) {
		cc[s[i]-'a']++;
		if (cc[s[i]-'a'] == 1) cnt++;
	}
	if (s.size() < k) cout << "impossible";
	else cout << max(0LL, k-cnt);
	return 0;
}

