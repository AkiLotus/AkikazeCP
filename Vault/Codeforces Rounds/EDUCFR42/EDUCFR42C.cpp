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

typedef pair<string, ll> psl;

bool isSquare(string z) {
	ll a = 0;
	for (ll i=0; i<z.size(); i++) {
		a *= 10; a += (z[i] - '0');
	}
	ll tmp = sqrt(a);
	return (tmp * tmp == a);
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	string n; cin >> n; queue<psl> Q; Q.push(mp(n, 0LL));
	while (!Q.empty()) {
		string z = Q.front().fi; ll st = Q.front().se; Q.pop();
		//cout << "working at " << z << " " << st << endl;
		if (isSquare(z)) {cout << st; return 0;}
		if (z.size() == 1) continue;
		for (ll i=0; i<z.size(); i++) {
			if (i != 0 || (i == 0 && z[i+1] != '0')) {
				string p = z; p.erase(i, 1);
				Q.push(mp(p, st+1));
			}
		}
	}
	cout << "-1";
	return 0;
}
