// Author  : Nguyen Duy Tung D12CN1
// Problem : Con kien
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001
// X de tinh tong day

int n,m;
int A[MAX][MAX];


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
    for ( int i=1; i<=n; i++ )
        for ( int j=1; j<=m; j++ )
            cin>>A[i][j];
}
int L[MAX][MAX];
void process(){

    for ( int j=1; j<=m; j++ )
        for ( int i=1; i<=n; i++ )
            L[i][j] = A[i][j] + max( L[i-1][j-1], max(L[i][j-1], L[i+1][j-1]) );
    for ( int i=1; i<=n; i++ ){
        for ( int j=1; j<=m; j++ )
            cout<<L[i][j]<<" ";
        cout<<endl;
    }

    int Max = L[1][m];
    int po = 1;
    for ( int i=2; i<=n; i++ )
        if( Max < L[i][m] ){
            Max = L[i][m];
            po = i;
        }
    stack <char> st;
    int x = m;
    cout<<L[po][x]<<endl;
    while( x!=1 ){
        if( L[po][x-1] > L[po+1][x-1] && L[po][x-1] > L[po+1][x-1]){
            st.push( 'R' );
        }
        else if( L[po+1][x-1] > L[po][x-1] && L[po+1][x-1] > L[po-1][x-1] ){
            st.push( 'U' );
            po = po+1;
        }
        else{
            st.push( 'D' );
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









