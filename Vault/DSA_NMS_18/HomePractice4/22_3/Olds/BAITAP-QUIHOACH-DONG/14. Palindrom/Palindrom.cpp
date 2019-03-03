// Author  : Nguyen Duy Tung D12CN1
// Problem : Dien dau
#include <iostream>
#include <fstream>
#include <stack>
#include <cstring>
#include <algorithm>
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
    cin>>S;
    X = S;
    reverse( X.begin(), X.end() );
}

void process(){

    memset(mark,0,sizeof(mark));
    for ( int i=1; i<=S.length(); i++ )
    for ( int j=1; j<=X.length(); j++ )
        if ( S[i-1]==X[j-1] )   mark[i][j] = mark[i-1][j-1]+1;
        else                    mark[i][j] = max( mark[i-1][j], mark[i][j-1] );
    cout<<S.length()-mark[S.length()][X.length()];
}









