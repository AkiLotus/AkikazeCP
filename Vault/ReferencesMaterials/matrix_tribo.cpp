#include <bits/stdc++.h>
 
using namespace std;
 
#define LL long long
 
const int size = 4;
 
struct matrix{
	LL a[size +1][size +1 ];
};
LL N;
matrix A,mtx1;
const LL base = 1e15 + 7;
 
LL nhan(LL A, LL B){
	LL res = 0, x;
   	while (B){
		x = B%10;
	    res = (res + (A*x) % base) % base;
	    A = (A*10) % base;
	    B /= 10;
	}
   	return (res % base);
}
 
matrix operator * ( matrix X, matrix Y){
	matrix Z ;
	for (int i=1; i<=size; i++){
		for (int j=1; j<=size; j++){
			Z.a[i][j] = 0;
			for (int k=1; k<=size; k++){
				Z.a[i][j] +=  nhan (X.a[i][k] , Y.a[k][j]);
				Z.a[i][j] %= base;
			}
		}
	}
	return Z;
}
 
 
matrix luythua (matrix X , LL N){
	matrix Y ; 
	if (N==0){
		Y = mtx1;
		return X;
	} 
	if (N==1){
		return X;
	}
	Y = luythua (X,N/2);
	Y = Y*Y;
	if (N%2) Y = Y*X;
	return  Y ;
}
 
void init(){
	A.a[1][1] = 1;A.a[1][2] = 1;A.a[1][3] = 1;A.a[1][4] = 1;
	A.a[2][1] = 0;A.a[2][2] = 1;A.a[2][3] = 1;A.a[2][4] = 1;
	A.a[3][1] = 0;A.a[3][2] = 1;A.a[3][3] = 0;A.a[3][4] = 0;
	A.a[4][1] = 0;A.a[4][2] = 0;A.a[4][3] = 1;A.a[4][4] = 0;
	
	for (int i=1; i<=size; i++){
		for (int j=1; j<=size; j++){
			mtx1.a[i][j]= 0;
		}
	}
	for (int i=1; i<=size ; i++){
		mtx1.a[i][i] = 1;
	}
}
 
void ghi(matrix A){
	for (int i=1; i<=size; i++){
		for (int j=1; j<=size; j++){
			cout<<A.a[i][j]<<' ';
		}
		cout<<endl;
	}
}
 
 
void build(){
	if (N<=3){
		if (N==1) cout<<1;
		else if (N==2) cout<<3;
		else cout<<6;
		cout<<endl;
		return ;
	}
	matrix B = luythua(A,N-3);
	cout << (6*B.a[1][1] + 3*B.a[1][2] + 2*B.a[1][3] + 1*B.a[1][4]) % base<<endl;
}
 
int main(){
	//freopen("vostribo.inp","r",stdin);
	int T;
	cin>>T;
	init();
	while (T--){
		cin>>N;
		build();
	}
} 
