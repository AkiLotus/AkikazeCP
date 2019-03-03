// Author  : Nguyen Duy Tung D12CN1
// Problem : Vali
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 1001
int n,w;
int a[MAX]; //  trong luong
int b[MAX]; //  gia tri


void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>n>>w;
    for ( int i=1; i<=n; i++ )
        cin>>a[i];
    for ( int i=1; i<=n; i++ )
        cin>>b[i];
}

void process(){
    int L[n+1][w+1];
    memset(L,0,sizeof(L) );
    for ( int i=1; i<=n; i++ ){
        for ( int j=1; j<=w; j++ )
            if( j-a[i]>=0 && L[i-1][j-a[i]]+b[i]>L[i-1][j] ){
                L[i][j] = L[i-1][j-a[i]]+b[i];
            }
            else{
                L[i][j] = L[i-1][j];
            }
    }
    cout<<L[n][w];
}





