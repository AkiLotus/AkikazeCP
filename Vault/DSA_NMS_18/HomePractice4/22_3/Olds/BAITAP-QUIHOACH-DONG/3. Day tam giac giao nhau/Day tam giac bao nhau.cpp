// Author  : Nguyen Duy Tung D12CN1
// Problem : Day tam giac bao nhau
#include <iostream>
#include <fstream>
#include <cmath>
#include <stack>
using namespace std;
typedef pair<double,double> PDD;    //  1 diem tren mat phang toa do
#define fi first
#define se second
#define MAX 1001
typedef struct {
    double S;   // dien tich tam giac
    PDD A,B,C;
} triangle;     // 1 tam giac gom 3 dinh la 3 diem va dien tich

int n;
triangle tria[ MAX ];
double saiSo = 0.00005;    // muc sai so cho phep
void init();	// nhap gia tri
bool checkPoint(PDD,triangle);    // kiem tra tam giac ben trong tam giac
void process();	// ham thuc hien
double dis(PDD,PDD);   // tinh khoang cach giua 2 diem
double areaHerong(PDD,PDD,PDD);    // tinh dien tich cua 1 tam giac
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>n;
    for ( int i=1; i<=n; i++ ){
        cin>>tria[i].A.fi>>tria[i].A.se;
        cin>>tria[i].B.fi>>tria[i].B.se;
        cin>>tria[i].C.fi>>tria[i].C.se;
        tria[i].S = areaHerong( tria[i].A, tria[i].B, tria[i].C );
    }
    for ( int i=1; i<n; i++ )    // sap xep mang tria theo dien tich
        for ( int j=i+1; j<=n; j++ )
            if( tria[j].S<tria[i].S )
                swap( tria[i], tria[j] );
}

bool checkPoint( PDD Z, triangle tmp){
    double s1 = areaHerong( Z, tmp.A, tmp.B );
    double s2 = areaHerong( Z, tmp.B, tmp.C );
    double s3 = areaHerong( Z, tmp.C, tmp.A );
    return  fabs( tmp.S - s1 - s2 - s3 ) <= saiSo;
}


void process(){
    int mark[MAX];
    int luu[MAX];
    int po, res=-1;
    for ( int i=1; i<=n; i++ ){
        mark[i] = 1;
        luu[i] = 0;
        for ( int j=1; j<i; j++ ){
            if (    checkPoint( tria[j].A, tria[i])&&
                    checkPoint( tria[j].B, tria[i])&&
                    checkPoint( tria[j].C, tria[i])&& mark[j]+1>mark[i] ){
                mark[i] = mark[j] + 1;
                luu[i] = j;
            }
        }
        if ( res<mark[i] ){
            res = mark[i];
            po = i;
        }
    }
    cout<<res<<endl;
    stack <int> st;
    while( po ){
        st.push( po );
        po = luu[po];
    }
    while( !st.empty() ){
        po = st.top();
        st.pop();
        cout<<tria[po].A.fi<<" "<<tria[po].A.se<<" ";
        cout<<tria[po].B.fi<<" "<<tria[po].B.se<<" ";
        cout<<tria[po].C.fi<<" "<<tria[po].C.se<<endl;
    }
}

double dis(PDD x,PDD y){
    double dx = x.fi-y.fi;
    double dy = x.se-y.se;
    return sqrt( dx*dx + dy*dy );
}

double areaHerong(PDD A, PDD B, PDD C){
    double a = dis( A, B );
    double b = dis( B, C );
    double c = dis( C, A );
    double p = (a+b+c)/2;
    return sqrt( p*(p-a)*(p-b)*(p-c) );
}




