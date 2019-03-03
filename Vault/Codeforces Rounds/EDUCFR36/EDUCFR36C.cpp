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

string a, b, ans = "", tmp = "";
ll al, bl;
vector<ll> cc(10, 0);
bool equalMode = true;

void Try_(ll pos, ll dig) {
	tmp[pos] = char(48+dig);
	if (ans[pos] > char(48+dig)) {
		return;
	}
	if (cc[dig] == 0) {
		return;
	}
	if (pos == al-1) {
		ans = max(ans, tmp); return;
	}
	cc[dig]--;
	if (tmp[pos] == b[pos] && equalMode) {
		for (ll i=(b[pos+1]-'0'); i>=0; i--) Try_(pos+1, i);
	}
	else {
		if (equalMode) {
			equalMode = false;
			for (ll i=9; i>=0; i--) Try_(pos+1, i);
			equalMode = true;
		}
		else {
			for (ll i=9; i>=0; i--) Try_(pos+1, i);
		}
	}
	cc[dig]++;
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> a >> b; al = a.size(); bl = b.size();
	for (ll i=0; i<al; i++) {
		ans += "0"; tmp += "0";
	}
	if (bl > al) {
		bl = al; b = "";
		for (ll i=0; i<bl; i++) b += "9";
	}
	for (ll i=0; i<al; i++) cc[a[i]-'0']++;
	for (ll i=(b[0]-'0'); i>0; i--) Try_(0, i);
	cout << ans;
	return 0;
}
