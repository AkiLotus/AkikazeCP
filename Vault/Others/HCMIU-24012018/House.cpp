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
	int n, ans = 0; string s; cin >> n >> s;
	for (int i=0; i<n; i++) {
		int tmp = i;
		while (i+1 < n && s[i+1] == s[i]) i++;
		int len = i - tmp + 1;
		ans += len / 2;
	}
	cout << ans;
	return 0;
}

