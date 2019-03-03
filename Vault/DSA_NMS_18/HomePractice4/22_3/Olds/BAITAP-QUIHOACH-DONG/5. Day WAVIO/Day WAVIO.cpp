// Author  : Nguyen Duy Tung D12CN1
// Problem : Day WAVIO
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#define MAX 1001
int n;
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
    for ( int i=1; i<=n; i++ )
        cin>>a[i];
}

void process(){
    int P[MAX], Q[MAX];
    int lP[MAX], lQ[MAX];   // luu vet
    for ( int i=1; i<=n; i++ ){
        P[i] =  1;
        lP[i] = 0;
        for ( int j=1; j<i; j++ ){
            if ( a[j]<a[i] && P[j]+1>P[i] ){
                P[i] = P[j] + 1;
                lP[i] = j;
            }
        }
    }
    for ( int i=n; i>=1; i-- ){
        Q[i] =  1;
        lQ[i] = 0;
        for ( int j=n; j>i; j-- ){
            if ( a[i]>a[j] && Q[j]+1>Q[i] ){
                Q[i] = Q[j] + 1;
                lQ[i] = j;
            }
        }
    }
    int res = 0, po;
    for ( int i=1; i<=n; i++ ){
        if ( res<P[i]+Q[i] ){
            res = P[i]+Q[i];
            po = i;
        }
    }
    cout<<res-1<<endl;// do phan tu tai po duoc tinh 2 lan
    stack <int> st;
    int mid = po;
    while( po ){
        st.push( po );
        po = lP[po];
    }
    while( !st.empty() ){
        cout<<a[ st.top() ]<<" ";
        st.pop();
    }
    po = mid;
    while( lQ[po] ){
        cout<<a[lQ[po]]<<" ";
        po = lQ[po];
    }
}





