// Author  : Nguyen Duy Tung D12CN1
// Problem : Dien dau
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
using namespace std;
#define MAX 1001
// X de tinh tong day
string S,X;
int mark[MAX][MAX];
void init();	// nhap gia tri
void process();	// ham thuc hien
int main(){		// ham MAIN
	freopen ("data.in","r",stdin);
	//freopen ("data.out","w",stdout);

	init();
	process();
}

void init(){
    cin>>S>>X;
    //cout<<S<<endl<<X<<endl;
}

void process(){

    memset(mark,0,sizeof(mark));        // khoi tao moi phan tu cua mang deu bang 0
    for ( int i=1; i<=S.length(); i++ )
    for ( int j=1; j<=X.length(); j++ )
        if ( S[i-1]==X[j-1] )   mark[i][j] = mark[i-1][j-1]+1;
        else                    mark[i][j] = max( mark[i-1][j], mark[i][j-1] );
    string vet="";
    int x = S.length(), y = X.length();
    while( x>0 && y>0 ){
        if ( mark[x][y]==mark[x-1][y-1]+1 ) {
            vet = S[x-1]+vet;
            x--;
            y--;
            continue;
        }
        if ( mark[x][y]==mark[x-1][y] ) x--;
        else                            y--;
    }
    cout<<mark[S.length()][X.length()]<<endl<<vet;
}









