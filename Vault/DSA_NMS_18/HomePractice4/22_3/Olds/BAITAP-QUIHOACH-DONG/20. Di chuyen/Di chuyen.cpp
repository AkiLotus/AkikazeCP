// Author  : Nguyen Duy Tung D12CN1
// Problem : Di chuyen
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001


int n,m;
int V[MAX][MAX];


void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	//freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>n>>m;
    for ( int i=1; i<=n; i++ ){
        for ( int j=1; j<=m; j++ )
            cin>>V[i][j];
    }
}
int L[MAX][MAX];
void process(){
    for ( int i=1; i<=n; i++ )
        for ( int j=1; j<=m; j++ )
            L[i][j] = max( L[i-1][j], max( L[i-1][j-1], L[i-1][j+1] ) ) + V[i][j];
    int Max = L[n][1];
    int po = 1;
    for ( int j=2; j<=m; j++ )
        if( Max < L[n][j] ){
            Max = L[n][j];
            po = j;
        }
    stack <char> st;
    int x = n;
    cout<<L[x][po]<<endl;
    while( x!=1 ){
        if( L[x-1][po] > L[x-1][po-1] && L[x-1][po] > L[x-1][po+1]){
            st.push( 'U' );
        }
        else if( L[x-1][po+1] > L[x-1][po-1] && L[x-1][po+1] > L[x-1][po] ){
            st.push( 'L' );
            po = po+1;
        }
        else{
            st.push( 'R' );
            po = po-1;
        }
        x--;
    }
    cout<<po<<" ";
    while( !st.empty() ){
        cout<<st.top();
        st.pop();
    }
}









