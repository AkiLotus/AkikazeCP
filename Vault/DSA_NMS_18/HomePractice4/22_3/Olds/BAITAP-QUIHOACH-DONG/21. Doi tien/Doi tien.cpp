// Author  : Nguyen Duy Tung D12CN1
// Problem : Di chuyen
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;
#define MAX 1001


int n,S;
int V[MAX];


void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	//freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>n>>S;
    for ( int i=1; i<=n; i++ ){
        cin>>V[i];
    }
}
int L[MAX][MAX];
int vet[MAX][MAX];
void process(){
    sort( V+1, V+n+1 );
    for ( int j=1; j<=S; j++ )  L[0][j] = INT_MAX;
    for ( int i=1; i<=n; i++ )
        for ( int j=V[1]; j<=S; j++ ){
            if( j<V[i ] )   L[i][j] = L[i-1][j];
            else    L[i][j] = min( L[i-1][j], L[i][ j-V[i] ]+1 );
        }
    stack <int> st;
    int x = n, y = S;
    while( y ){
        if( L[x][y]==L[x-1][y] )    x--;
        else{
            y -= V[x];
            st.push( V[x] );
        }
    }
    cout<<L[n][S]<<endl;
    while( !st.empty() ){
        cout<<st.top()<<" ";
        st.pop();
    }
}









