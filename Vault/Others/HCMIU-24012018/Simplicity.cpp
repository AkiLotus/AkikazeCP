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
	string s; vector<int> cc(26, 0); int cnt = 0; cin >> s;
	for (int i=0; i<s.size(); i++) {
		cc[s[i]-'a']++;
	}
	sort(cc.begin(), cc.end(), greater<int>());
	cout << s.size() - cc[0] - cc[1];
	return 0;
}

