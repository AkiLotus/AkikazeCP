#include <bits/stdc++.h>
#define ll long long
#define FOR(v,a,b) for(int v=a;v<b;v++)
#define FOD(v,a,b) for(int v=a;v>b;v--)
#define fi first
#define se second
using namespace std;

string s;
int n,f[300];

int main(){
	cin>>s;
	n=s.size();
	int mx=0;
	string ans;
	FOR(i,0,n){
	    int tmp=0;
        memset(f,0,sizeof(f));
        string st="";
        FOR(j,i,n){
            st+=s[j];
            f[s[j]]++;
            if(f[s[j]]==1) tmp++;
            else if(f[s[j]]==2) tmp--;
            if(tmp>mx){
                mx=tmp;
                ans=st;
            }
            else if(tmp==mx && st<ans) ans=st;
        }
	}
	cout<<ans;
	return 0;
}
