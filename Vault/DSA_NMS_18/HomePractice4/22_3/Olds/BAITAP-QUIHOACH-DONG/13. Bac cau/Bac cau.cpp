// Author  : Nguyen Duy Tung D12CN1
// Problem : Bac cau
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 1001
int n,m;
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
    cin>>n;
    for ( int i=1; i<=n; i++ )
        cin>>A[i];
    cin>>m;
    for ( int i=1; i<=m; i++ )
        cin>>B[i];
}
int L[MAX][MAX];
void process(){
    memset(L,0,sizeof(L));
    for ( int i=1; i<=n; i++ )
        for ( int j=1; j<=m; j++ )
        if ( A[i]==B[j] )   L[i][j] = L[i-1][j-1] + 1;
        else    L[i][j] = max( L[i-1][j], L[i][j-1] );
    cout<<L[n][m]<<endl;
    stack < pair<int,int> > st;
    int x = n, y = m;
    while( x && y ){
        if ( L[x][y] == L[x-1][y-1]+1 ){
            st.push( make_pair(x,y) );
            x--;
            y--;
            continue;
        }
        if ( L[x-1][y] == L[x][y] ) x--;
        else                        y--;
    }
    while( !st.empty() ){
        cout<<st.top().first<<" "<<st.top().second<<endl;
        st.pop();
    }
}









