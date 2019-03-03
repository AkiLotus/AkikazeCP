// Author  : Nguyen Duy Tung D12CN1
// Problem : Day con co tong bang S
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 1001
int n,S,T;
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
    cin>>n;
    T = 0;
    for ( int i=1; i<=n; i++ ){
        cin>>a[i];
        T += a[i];
    }
}

void process(){
    S = T/2;
    int L[n+1][S+1];
    memset(L,0,sizeof(L));
    for ( int i=0; i<=n; i++ )
        L[i][0] = 1;
    for ( int i=1; i<=n; i++ )
        for ( int j=0; j<=S; j++ ){
            L[i][j] = (L[i-1][j]==1 || L[i-1][j-a[i]]==1);
        }
    while( L[n][S]==0 ) S--;
    cout<<S<<" "<<T-S<<endl;
    int x = n,y = S;
    stack <int> st;
    int mark[n+1];
    while( y ){
        if ( L[x-1][y] ){
            x--;
            continue;
        }
        if ( L[x-1][y-a[x]] ){
            st.push( a[x] );
            mark[x] = 1;
            y-=a[x];
            x--;
        }
    }
    cout<<"Part 1: ";
    while( !st.empty() ){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<"Part 2: ";;
    for ( int i=1; i<=n; i++ )
        if ( mark[i]!=1 )   cout<<a[i]<<" ";
}









