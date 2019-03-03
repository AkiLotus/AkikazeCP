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

ll n, personCount = 0;
vector<string> friends;
vector<vector<string>> numbers;

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	while (n--) {
		string name; cin >> name;
		ll pos = find(friends.begin(), friends.end(), name) - friends.begin();
		if (pos == personCount) {friends.push_back(name); numbers.push_back(vector<string>(0)); personCount++;}
		ll t; cin >> t;
		while (t--) {
			string num; cin >> num; numbers[pos].push_back(num);
		}
	}
	cout << personCount << endl;
	for (ll i=0; i<personCount; i++) {
		for (ll j=numbers[i].size()-1; j>=0; j--) {
			for (ll k=0; k<j; k++) {
				if (numbers[i][k].size() < numbers[i][k+1].size()) {
					string tmp = numbers[i][k];
					numbers[i][k] = numbers[i][k+1];
					numbers[i][k+1] = tmp;
				}
			}
		}
		for (ll j=0; j<numbers[i].size(); j++) {
			string suffix = "";
			for (ll k=numbers[i][j].size()-1; k>=0; k--) {
				suffix.insert(0, 1, numbers[i][j][k]);
				for (ll l=j+1; l<numbers[i].size(); l++) {
					if (numbers[i][l] == suffix) {
						numbers[i].erase(numbers[i].begin()+l); l--;
					}
				}
			}
		}
		cout << friends[i] << " " << numbers[i].size();
		for (ll j=0; j<numbers[i].size(); j++) cout << " " << numbers[i][j]; cout << endl;
	}
	return 0;
}

