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

ll n, start, x;
ll mx = -1, pos = -1;
vector<ll> a(55555, 0);
vector<ll> nex(55555, -9);

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	srand(time(NULL));
	cin >> n >> start >> x;
	cout << "? " << start << endl; fflush(stdout);
	ll z, nxt; cin >> z >> nxt; mx = z; pos = start;
	nex[start] = nxt; a[start] = z;
	for (ll i=1; i<min(1000LL, n); i++) {
		ll rd = rand() % n + 1;
		while (nex[rd] != -9) rd = rand() % n + 1;
		cout << "? " << rd << endl; fflush(stdout);
		cin >> z >> nxt;
		if (z > mx && z <= x) {
			mx = z; pos = rd;
		}
		nex[rd] = nxt; a[rd] = z;
	}
	if (n <= 1000) {
		if (mx == x) cout << "! " << x;
		else if (nex[pos] > n || nex[pos] < 1) cout << "! -1";
		else cout << "! " << a[nex[pos]] << endl; return 0;
	}
	for (ll i=0; i<1000; i++) {
		cout << "? " << pos << endl; fflush(stdout);
		cin >> z >> nxt;
		if (z > mx && z <= x) {
			mx = z;
		}
		else if (z > x) {
			cout << "! " << z << endl; return 0;
		}
		nex[pos] = nxt; a[pos] = z;
		pos = nxt;
	}
	cout << "! -1\n";
	return 00;
}

