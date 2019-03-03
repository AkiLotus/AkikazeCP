#include <bits/stdc++.h>
using namespace std;
int p[300],sz[300];
void st(){
    for (int i=0;i<=200;++i){
            p[i]=i;
            sz[i]=1;
    }
}
int fd(int a){
  return (p[a]==a?a:p[a]=fd(p[a]));
}
bool jo(int a,int b){
  a=fd(a),b=fd(b);
    if (a==b)
           return 0;
     p[b]=a;
     sz[a]+=sz[b];
    return 1;
}
int main()
{
    st();
    int n,m,x,y,ct=0;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>x>>y;
                if (!jo(x,y)){
                    if (sz[fd(x)]%2)
                          ++ct;
                }
    }
       if ((n-ct)%2)
           ++ct;
          cout<<ct<<endl;
    return 0;
}