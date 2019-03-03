// Author  : Nguyen Duy Tung D12CN1
// Problem : Bo tri phong hop
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair<int,int> PII;		// kieu pair co 2 phan tu la kieu nguyen
#define fi first
#define se second
#define MAX 10001
int n;
PII a[MAX];

void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
    freopen ("data.in","r",stdin);
    freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
	cin>>n; // so luong cuoc hop
	for ( int i=1; i<=n; i++ )
		cin>>a[i].fi>>a[i].se;  // thoi gian bat dau va ket thuc cua moi cuoc hop
}

void process(){
	sort(a+1,a+n+1);	// sap xep mang a( mac dinh sap xep theo *first tang dan)
	int res[MAX];
	int luu[MAX],po;
	int maxRes = -1;
	for ( int i=1; i<=n; i++ ) {
		res[i] = 1;
		for ( int j=1; j<i; j++ )
			if ( a[j].se <= a[i].fi && res[j]+1>res[i] ){
                // neu cuoc hop j ket thuc truoc khi i bat dau
                // neu cuoc hop i tiep theo cuoc hop j thi co the xep duoc n cuoc hop nhat toi i
				res[i] = res[j] + 1;
				luu[i] = j;
            }
		if( maxRes < res[i] ){
            maxRes = res[i];    // so cuoc hop lop nhat co the phuc vu
            po = i;     // vi tri cuoc hop cuoi cung khi toi uu
		}
	}
	cout<<maxRes<<endl;     //  so cuoc hop toi da co the phuc vu
	stack <int> st; // ngan xep de dao lai thu tu cac cuoc hop
	while( po ){
        st.push( po );      // lay vi tri cac cuoc hop duoc xep
        po = luu[po];
	}
	while( !st.empty() ){
        po = st.top();
        st.pop();
        cout<<a[po].fi<<" "<<a[po].se<<endl;    // hien thi thoi gian cac cuoc hop

	}
}




