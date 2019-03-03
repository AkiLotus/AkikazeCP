#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define MOD 1000000007
using namespace std;
const double PI=acos(-1.0);
const int N = 1e6 + 5;

ll d[25];
bool check = true;

vector<int> get(ll x) {
	vector<int> vt(30,0);
	int i = 2;
	while( x > 0 && i < 25) {
		if( x %i == 0) {
			while( x%i ==0 ){
				vt[i]++;
				x/=i;
			}
		}
		i++;
	}
	return vt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	/*#ifndef ONLINE_JUDGE
		freopen("../input.txt", "r", stdin);
		freopen("../output.txt", "w", stdout);
	#endif*/

	ll mmax = 1e18;
	d[1] = 1;
	for(ll i = 2; i <= 20 ; i ++) {
		d[i] = d[i-1] * i;
	}
	int n;
	ll x;
	cin>>n;
	while( n--) {
		cin>>x;
		check = false;
		if( x == 1) {
			cout<<"YES"<<endl;
			continue;
		}

		while( x > 1) {
			vector<int> vt = get(x);
			int sz = 25;
			while( sz > 1 &&  vt[sz] == 0) {
				sz--;
			}
			if( x % d[sz] != 0) {
				check = true;
				break;
			}
			x/= d[sz];
//			cout<<x<<endl;
		}
		if(check) {
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}



	return 0;
}
