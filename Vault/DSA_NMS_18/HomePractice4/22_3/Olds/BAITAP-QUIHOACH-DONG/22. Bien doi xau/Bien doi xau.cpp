// Author  : Nguyen Duy Tung D12CN1
// Problem : Di chuyen
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MAX 1001
#define fi first
#define se second.first
#define th second.second

string X,S;

void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>X>>S;
}
int L[MAX][MAX];
int vet[MAX][MAX];
void process(){
    int n = X.length();
    int m = S.length();
    for ( int i=1; i<=n; i++ )  L[i][0] = i;
    for ( int j=1; j<=m; j++ )  L[0][j] = j;
    for ( int i=1; i<=n; i++ )
        for ( int j=1; j<=m; j++ )
            if( X[i-1] == S[j-1] )  L[i][j] = L[i-1][j-1];
            else L[i][j] = min( L[i-1][j-1], min( L[i-1][j], L[i][j-1]) ) + 1;
    int x = n, y = m;
    stack < pair< char,pair<int,char > > > st;
    while( x && y ){
        if( L[x][y] == L[x-1][y-1]+1 ){
            st.push( make_pair( 'R', make_pair(x,S[y-1]) ) );
            x--;
            y--;
        }
        else if( L[x][y]==L[x][y-1]+1 ){
            st.push( make_pair( 'I', make_pair(x,S[y-1]) ) );
            y--;
        }
        else if( L[x][y]==L[x-1][y]+1){
            st.push( make_pair( 'D', make_pair(x,X[x-1]) ) );
            x--;
        }
        else {
            x--;
            y--;
        }
    }
    cout<<L[n][m]<<endl;
    for ( int i=L[x][y]; i>0; i-- ){
        st.push( make_pair( 'D', make_pair(x,X[x-1]) ) );
        x--;
    }
    while( !st.empty() ){
        cout<<st.top().fi<<" "<<st.top().se<<" "<<st.top().th<<endl;
        st.pop();
    }
}









