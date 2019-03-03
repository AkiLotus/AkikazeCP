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

string str; ll n;
vector<ll> power10(1000007, 1);
vector<ll> sum(1000007, 0);

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> str; n = str.size();
	for (ll i=1; i<1000007; i++) {
		power10[i] = (power10[i-1] * 10) % MOD;
	}
	sum[0] = str[0] - '0';
	for (ll i=1; i<n; i++) {
		sum[i] = (sum[i-1] * 10 + (str[i] - '0')) % MOD;
	}
	for (ll i=n/3; i<=n/2; i++) {
		for (ll j=-1; j<1; j++) {
			ll x = i+j, z = i, y = n - x - z;
			if (x == 0 || y == 0 || z == 0) continue;
			ll tmp1 = sum[x-1], tmp2 = sum[x+y-1] - (sum[x-1] * power10[y]) % MOD, tmp3 = sum[n-1] - (sum[n-z-1] * power10[z]) % MOD;
			while (tmp2 < 0) tmp2 += MOD; while (tmp3 < 0) tmp3 += MOD;
			if ((x == 1 || (x != 1 && str[0] != '0')) && (y == 1 || (str[x] != '0' && y != 1)) && (z == 1 || (str[x+y] != '0' && z != 1))) {
				if ((tmp1 + tmp2) % MOD == tmp3) {
					for (ll i=0; i<x; i++) cout << str[i]; cout << "+";
					for (ll i=x; i<x+y; i++) cout << str[i]; cout << "=";
					for (ll i=x+y; i<n; i++) cout << str[i]; return 0;
				}
			}
			tmp1 = sum[y-1], tmp2 = sum[x+y-1] - (sum[y-1] * power10[x]) % MOD, tmp3 = sum[n-1] - (sum[n-z-1] * power10[z]) % MOD;
			while (tmp2 < 0) tmp2 += MOD; while (tmp3 < 0) tmp3 += MOD;
			if ((y == 1 || (y != 1 && str[0] != '0')) && (x == 1 || (str[y] != '0' && x != 1)) && (z == 1 || (str[x+y] != '0' && z != 1))) {
				if ((tmp1 + tmp2) % MOD == tmp3) {
					for (ll i=0; i<y; i++) cout << str[i]; cout << "+";
					for (ll i=y; i<x+y; i++) cout << str[i]; cout << "=";
					for (ll i=x+y; i<n; i++) cout << str[i]; return 0;
				}
			}
		}
	}
	return 0;
}

