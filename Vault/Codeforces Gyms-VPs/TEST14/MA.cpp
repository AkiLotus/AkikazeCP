#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
using namespace std;
const int N = 1e6 +5;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int n, d; string s; cin >> n >> d >> s;
	int res = 0, it = 0;
	while (it < n-1) {
		res++;
		int next = min(it+d, n-1);
		while (next > it && s[next] == '0') {
			next--;
		}
		if (next == n-1) break;
		if (next == it) {
			cout << "-1";
			return 0;
		}
		it = next;
	}
	cout << res;
	return 0;
}

