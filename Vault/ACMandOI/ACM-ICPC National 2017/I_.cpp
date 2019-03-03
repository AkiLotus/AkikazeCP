#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
using namespace std;
const int N = 1e6 +5;
ll cnt   = 0;
int A,B;
string st, ed;
vector<int> vt[1000007];
string getString(int x) {
	string s = "";
	while( x > 0) {
		char c = (char)(x%10 + '0');
		s = c + s;
		x/=10;
	}
	return s;
}
string DichPhai(string s) {
	if( s.size()  <= 1) return s;
	return s[s.size()-1] + s.substr(0, s.size()-1);
}
bool isThoaMan(string s, string t) {
	// t ko chua so 0 o dau.
	// t > s;
	if( t[0] =='0') return false;
//	return s < t;
	return s!= t;
}
int getSo(string s) {
	int x = 0;
	for(int i = 0 ;  i < s.size() ; i ++) {
		x = x*10 + (int)(s[i] -'0');
	}
	return x;
}
void work(int i) {
	string s = getString(i);
	string y; string trangThai =s;
//	cout<<i<<"::";
	for(int j = 0 ; j < s.size()-1 ; j++) {
		y = DichPhai(trangThai);
		trangThai = y;
//		cout<<y<<" ";
		if(isThoaMan(s,y)) {
			vt[i].push_back(getSo(y));
		}
	}
//	cout<<endl;
}
int main() {
//	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	for (int i=1; i<=10000; i++) {
		work(i);
		sort(vt[i].begin(),vt[i].end());
		cout<<i<<":";
		for(int j = 0 ; j < vt[i].size() ; j++) {
			cout<<vt[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int t;
	cin>>t;
	while(t--){
		cnt =  0;
		cin>>A>>B;
		for(int i = A; i <= B ;  i++) {
			for(int j = 0 ; j < vt[i].size() ; j++) {
				if( vt[i][j] >= A && vt[i][j] <= B) {
					cnt++;
				}
				else break;
			}
		}
		cout<< cnt/2<<endl;
	}
	
	
	return 0;
}
