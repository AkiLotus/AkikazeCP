// Author  : Nguyen Duy Tung D12CN1
// Problem : Day con co tong bang S
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 1001
int n,S;
int a[MAX];

void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>n>>S;
    for ( int i=1; i<=n; i++ )
        cin>>a[i];
}

void process(){
    int L[n+1][S+1];
    memset(L,0,sizeof(L));
    for ( int i=0; i<=n; i++ )
        L[i][0] = 1;
    for ( int i=1; i<=n; i++ )
        for ( int j=0; j<=S; j++ ){
            if( j>=a[i] )    L[i][j] = (L[i-1][j]==1 || L[i-1][j-a[i]]==1);
            else            L[i][j] = L[i-1][j];
        }
    if ( L[n][S]==0 ){
        cout<<"Impossible.";
        return;
    }
    else{
        int x = n,y = S;
        int k = 0;
        stack <int> st;
        while( y ){
            if ( L[x-1][y] ){
                x--;
                continue;
            }
            if ( L[x-1][y-a[x]] ){
                st.push( a[x] );
                k++;
                y-=a[x];
                x--;
            }
        }
        cout<<k<<endl;
        while( !st.empty() ){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}









