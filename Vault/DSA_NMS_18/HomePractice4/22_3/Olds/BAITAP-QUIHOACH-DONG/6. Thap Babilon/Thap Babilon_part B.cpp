// Author  : Nguyen Duy Tung D12CN1
// Problem : Thap Babilon_xep sao cho thap la cao nhat
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
#define MAX 1001
typedef pair < int, int > PI2;  // 2 phan tu
typedef pair < int, PI2 > PI3;  // 3 phan tu
#define fi first            // thanh phan 1 cua PI3
#define se second.first     // thanh phan 2 cua PI3
#define th second.second    // thanh phan 3 cua PI3


PI3 a[MAX];
int n;
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
    for ( int i=1; i<=n; i++){
        cin>>a[i].fi>>a[i].se>>a[i].th;
        /*
            thanh phan 1 : so lon nhat la chieu dai
            thanh phan 2 : so lon nhat la chieu rong
            thanh phan 3 : so lon nhat la chieu cao
        */
        if ( a[i].fi<a[i].se )  swap( a[i].fi,a[i].se );
        if ( a[i].fi<a[i].th )  swap( a[i].fi,a[i].th );
        if ( a[i].se<a[i].th )  swap( a[i].se,a[i].th );
    }
    for ( int i=1; i<n; i++ )
        for ( int j=i+1; j<=n; j++ )
            if ( a[i].fi<a[j].fi )
                swap( a[i], a[j] );
}

void process(){
    int mark[MAX];
    int luu[MAX];
    int po, res = 0;
    for ( int i=1; i<=n; i++ ){
        mark[i] = a[i].th;
        luu[i] = 0;
        for ( int j=1; j<i; j++ )
            if ( a[i].se <=a[j].se && mark[i]<mark[j]+a[i].th ){
                mark[i] = mark[j]+a[i].th;
                luu[i] = j;
            }
        if ( res<mark[i] ){
            res = mark[i];
            po = i;
        }
    }
    int k = 0;
    stack <int> st;
    while( po ){
        st.push( po );
        k++;
        po = luu[po];
    }
    cout<<k<<" "<<res<<endl;
    while( !st.empty() ){
        po = st.top();
        st.pop();
        cout<<a[po].fi<<" "<<a[po].se<<" "<<a[po].th<<endl;
    }
}









