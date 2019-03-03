// Author  : Nguyen Duy Tung D12CN1
// Problem : Dien dau
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 1001
// X de tinh tong day
int n,S,X;
int a[MAX];

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
    X = 0;
    for ( int i=1; i<=n; i++ ){
        cin>>a[i];
        X += a[i];
    }
}

void process(){
    int mark[MAX][X+1];
    memset(mark,0,sizeof(mark));
    mark[1][ a[1] ] = 1;
    for ( int i=2; i<=n; i++ )
    for ( int j=1; j<=X; j++ ){
        if ( mark[i-1][j+a[i]] )  mark[i][j] = 1;
        if ( j>=a[i] && mark[i-1][j-a[i]] )    mark[i][j] = 1;
    }

    if ( mark[n][S] )   {
        cout<<"YES\n";
        stack <int> st;
        for ( int i=n; i>1; i-- )
            if ( mark[i-1][S+a[i]] ){
                st.push(1);
                S += a[i];
            }
            else{
                st.push(0);
                S-=a[i];
            }
        cout<<a[1];
        for ( int i=2; i<=n; i++ ){
            if ( st.top() ) cout<<"-"<<a[i];
            else            cout<<"+"<<a[i];
            st.pop();
        }
    }
    else                cout<<"NO";
}









