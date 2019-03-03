// Author  : Nguyen Duy Tung D12CN1
// Problem : Day doi dau
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#define MAX 1001
int n,l,u;
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
    cin>>n>>l>>u;
    for ( int i=1; i<=n; i++ )
        cin>>a[i];
}

void process(){
    int P[MAX], Q[MAX];
    int lP[MAX], lQ[MAX];   // luu vet
    for ( int i=1; i<=n; i++ ){
        P[i] = Q[i] = 1;
        lP[i] = lQ[i] = 0;
        for ( int j=1; j<=i-l; j++ ){
            if ( a[j]<=a[i]-u && P[j]+1>Q[i] ){
                Q[i] = P[j] + 1;
                lQ[i] = j;
            }
            if ( a[i]<=a[j]-u && Q[j]+1>P[i] ){
                P[i] = Q[j] + 1;
                lP[i] = j;
            }
        }
    }
    int res = 0, po , f;//  f=1 mang Q, f=0 mang P
    for ( int i=1; i<=n; i++ ){
        if ( res<P[i] ){
            res = P[i];
            po = i;
            f = 1;
        }
        if ( res<Q[i] ){
            res = Q[i];
            po = i;
            f = 0;
        }
    }
    cout<<res<<endl;
    // truy vet
    stack <int> st;
    while( po ){
        st.push( po );
        if( f ){
            po = lP[po];
        }
        else{
            po = lQ[po];
        }
        f = 1-f;
    }
    while( !st.empty() ){
        cout<<a[ st.top() ]<<" ";
        st.pop();
    }
}





