// Author  : Nguyen Duy Tung D12CN1
// Problem : Farmer
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001


int n,m,S;
int A[MAX],B[MAX];


void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	//freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>n>>m>>S;
    for ( int i=1; i<=n+m; i++ ){
        cin>>A[i];
        B[i] = A[i]-(i>n);
    }
}
int L[MAX][MAX];
int vet[MAX];
void process(){
    for ( int i=1; i<=n+m; i++ )
    for ( int j=1; j<=S; j++ ){
        L[i][j] = L[i-1][j];
        if( j>A[i] && L[i][j]<L[i-1][j-A[i]] + B[i] )
            L[i][j] = L[i-1][j-A[i]]+B[i];
    }
    cout<<L[n+m][S];

}









