#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll m,giv;
    double in,amt;
    while(true){
        cin>>m>>in>>amt>>giv;
        if(m<0) {break;}
        double a[120]={0};
        ll b[120]={0};
        for(ll i=0;i<giv;i++){
            cin>>b[i];
            cin>>a[b[i]];
        }
        for(ll i=0;i<=m;i++){
            if(a[i]==0) a[i]=a[i-1];
        }
        double inamt=amt+in;
        ll month=0;
        double now=amt;
        inamt-=(a[0])*inamt;
        double sub=amt/m;
        while(inamt<=now){
              inamt*=(1.00-a[++month]);
              now-=sub;
        }
        if(month==1) cout<<month<<" month"<<endl;
        else cout<<month<<" months"<<endl;
    }
    return 0;
}
