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
	vector<ll> cc(200000, 0);
	ll n, k, cnt = 0; cin >> n >> k;
	multiset<ll> heap;
	ll pos = 0;
	while (n > 0) {
		if (n % 2 == 1) {
			cc[pos+190000]++; cnt++;
		}
		n /= 2; pos++;
	}
	if (cnt > k) {
		cout << "No"; return 0;
	}
	for (ll i=199999; i>0; i--) {
		if (cnt + cc[i] <= k) {
			cc[i-1] += cc[i] * 2;
			cnt += cc[i]; cc[i] = 0;
		}
		else break;
	}
	
	for (ll i=0; i<200000; i++) {
		for (ll j=0; j<cc[i]; j++) heap.insert(i-190000);
	}
	
	while (heap.size() < k) {
		auto it = heap.begin(); ll val = *it;
		heap.erase(it); heap.insert(val-1); heap.insert(val-1);
	}
	cout << "Yes\n";
	for (auto it=heap.end(); it!=heap.begin();) {
		it--; cout << *it << " ";
	}
	return 0;
}

