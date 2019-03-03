// Author  : Nguyen Duy Tung D12CN1
// Problem : Cho thue may
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair< int, int > PII;		// kieu pair co 2 phan tu la kieu nguyen
typedef pair< PII, int > PI3;		// kieu pair co 3 phan tu la kieu nguyen
// dinh nghia thu tu phan tu cho PI3
#define fi first.first  // thanh phan thu nhat
#define se first.second // thanh phan t2
#define th second       // thanh phan t3
#define MAX 10001
int n;
/* array:a co 3 thanh phan
        a.fi : la thoi gian bat dau thue
        a.se : la thoi gian ket thuc thue
        a.th : la so tien nhan duoc khi thue    */
PI3 a[MAX];

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
		cin>>a[i].fi>>a[i].se>>a[i].th;  // thoi gian bat dau va ket thuc cua moi cuoc hop
}

void process(){
	sort(a+1,a+n+1);	// sap xep mang a( mac dinh sap xep theo *first tang dan)
	int res[MAX];
	int luu[MAX],po;
	int maxRes = -1;
	for ( int i=1; i<=n; i++ ) {
		res[i] = a[i].th;
		for ( int j=1; j<i; j++ )
			if ( a[j].se <= a[i].fi && res[j]+a[i].th>res[i] ){
                res[i] = res[j] + a[i].th;
				luu[i] = j;
            }
		if( maxRes < res[i] ){
            maxRes = res[i];    // so tien lon nhat co the thu ve
            po = i;     // vi tri thoi gian cho thue may cuoi cung khi toi uu
		}
	}
	cout<<maxRes<<endl;
	stack <int> st; // ngan xep de dao lai thu tu cac trinh tu thue
	while( po ){
        st.push( po );
        po = luu[po];
	}
	while( !st.empty() ){
        po = st.top();
        st.pop();
        cout<<a[po].fi<<" "<<a[po].se<<" "<<a[po].th<<endl;    // hien thi thoi gian cac cuoc hop

	}
}




