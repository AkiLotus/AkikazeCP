// Author  : Nguyen Duy Tung D12CN1
// Problem : Day con don dieu dai nhat
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1001
// X de tinh tong day

int n;
int A[MAX];


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
}

void process(){

    int mark[MAX],vet[MAX];
    int po, maxres = -1;
    for ( int i=1; i<=n; i++ ){
        mark[i] = 1;
        vet[i] = 0;
        for ( int j=1; j<i; j++ )
        if ( A[j]<A[i] && mark[j]+1>mark[i] ){
            mark[i] = mark[j] + 1;
            vet[i] = j;
        }
        if ( maxres<mark[i] ){
            maxres = mark[i];
            po = i;
        }
    }
    cout<<maxres<<endl;
    stack <int> st;
    while( po ){
        st.push( po );
        po = vet[po];
    }
    while( !st.empty() ){
        cout<<A[ st.top() ]<<" ";
        st.pop();
    }
}









