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

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll t; cin >> t;
	while (t--) {
		string s; cin >> s; ll n = s.size();
		vector<ll> cc(10, 0); ll oc = 0;
		for (ll i=0; i<n; i++) {
			cc[s[i]-'0']++;
			if (cc[s[i]-'0'] % 2 != 0) oc++; else oc--;
		}
		bool flag = false;
		for (ll i=n-1; i>=0; i--) {
			if (flag) break;
			ll original = s[i] - '0';
			cc[original]--;
			if (cc[original] % 2 != 0) oc++; else oc--;
			for (ll j=original-1; j>=0; j--) {
				if (i == 0 && j == 0) break;
				if (flag) break;
				cc[j]++; if (cc[j] % 2 != 0) oc++; else oc--;
				if (oc <= (n-1) - i && (n-1-i-oc) % 2 == 0) {
					flag = true;
					priority_queue<ll> heap;
					for (ll x=0; x<10; x++) {
						if (cc[x] % 2 != 0) heap.push(x);
					}
					for (ll x=0; x<n-1-i-oc; x++) heap.push(9);
					for (ll x=0; x<i; x++) cout << s[x];
					cout << j;
					while (!heap.empty()) {
						cout << heap.top(); heap.pop();
					}
					cout << endl;
				}
				cc[j]--; if (cc[j] % 2 != 0) oc++; else oc--;
			}
		}
		if (!flag) {
			for (ll i=0; i<n-2; i++) cout << "9"; cout << endl;
		}
	}
	return 0;
}

