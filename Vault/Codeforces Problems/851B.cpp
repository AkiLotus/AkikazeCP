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
	ll ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if ((ax-bx)*(ax-bx) + (ay-by)*(ay-by) != (cx-bx)*(cx-bx) + (cy-by)*(cy-by)) {
		cout << "No"; return 0;
	}
	if (2*bx == ax + cx && 2*by == ay + cy) {
		cout << "No"; return 0;
	}
	cout << "Yes";
	return 0;
}

