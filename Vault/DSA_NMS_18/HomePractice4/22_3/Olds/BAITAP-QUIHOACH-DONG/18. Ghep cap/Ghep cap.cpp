// Author  : Nguyen Duy Tung D12CN1
// Problem : Ghep cap
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001


int n,k;
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
    cin>>k>>n;
    for ( int i=1; i<=k; i++ ){
        for ( int j=1; j<=n; j++ )
            cin>>V[i][j];
    }
}
int L[MAX][MAX];
void process(){
    for ( int i=1; i<=k; i++ )
    for ( int j=i; j<=n; j++ ){
        if( i==j )  L[i][j] = L[i-1][j-1] + V[i][j];
        else        L[i][j] = max( L[i-1][j-1]+V[i][j], L[i][j-1] );
    }
    int x = k, y = n;
    int sum = L[k][n];
    stack < pair < int, int > > st;
    while( x!=0 ){
        while( y>x && sum==L[x][y-1] )  y--;
        st.push( make_pair(x,y) );
        sum -= V[x][y];
        x--;
    }
    cout<<L[k][n]<<endl;
    while( !st.empty() ){
        cout<<st.top().first<<" "<<st.top().second<<endl;
        st.pop();
    }
}









