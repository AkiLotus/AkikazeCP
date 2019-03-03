#include <bits/stdc++.h>
#define LL long long
using namespace std;
int const nMax = 100005;
 
struct NODE{
    LL value, lazy ;
};
 
int n,m;
NODE T[nMax*4];
 
void down(int id, int l, int r){
	int m = (l+r)/2;
    T[id*2].value  += T[id].lazy*(m-l+1);
    T[id*2+1].value+= T[id].lazy*(r-m);
    T[id*2].lazy   += T[id].lazy;
    T[id*2+1].lazy += T[id].lazy;
    T[id].lazy = 0 ;
}
 
void update(int l, int r , int id , int u, int v,LL val){
    if (v<l || u>r) return ;
    if (u<=l && v>=r){
        T[id].lazy  += val ;
        T[id].value += val*(r-l+1) ;
        return ;
    }
    int mid = (l+r) / 2;
    down(id,l,r);
    update(l,mid, id*2 , u,v,val);
    update(mid+1,r,id*2+1,u,v,val);
    T[id].value = T[id*2].value + T[id*2+1].value;
}
 
LL extract(int l, int r, int id, int u, int v){
    if (v<l || u>r) return 0;
    if (u<=l && v>=r){
        return T[id].value;
    }
    down(id,l,r);
    int mid = (l+r) / 2;
    return extract (l,mid ,id*2, u ,v) + extract (mid+1,r,id*2+1,u,v);
}
 
int main(){
    cin>>n >> m;
    for (int i= 0 ; i<=4*n; i++){
        T[i].lazy = 0;
        T[i].value = 0;
    }
    for (int i = 1; i<=n; i++){
    	LL x ;
    	cin >> x ;
    	update(1,n,1,i,i,x);
	}
    for (int i= 1; i<=m; i++){
        int q , x, y ;
		LL value;
        cin>> q ;
        if (q == 2 ){
            cin >> x >> y >> value ;
            update(1,n,1,x,y,value);
        }
        else{
            cin >> x >> y ;
            cout<< extract (1,n,1,x,y) <<endl ;
        }
    }
}
  
