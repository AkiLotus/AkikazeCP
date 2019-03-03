#include <bits/stdc++.h>

using namespace std;

const int N = 2;
const int MOD = 1e9+7;

struct matrix
{
	long long a[3][3];

	matrix() {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				a[i][j] = 0;
			}
		}
	}
};



void unit(matrix &A) {
	for (int i = 1; i <= N; ++i) {
		A.a[i][i] = 1;
	}
}

matrix operator *(const matrix &A, const matrix &B) {
	matrix C;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			long long sum = 0;
			for (int k = 1; k <= N; ++k) {
				sum += (A.a[i][k] * B.a[k][j]) % MOD;
				sum %= MOD;
			}
			C.a[i][j] = sum;
		}
	}
	return C;
}

matrix pow_(matrix A, long long p) {
	matrix ans;
	unit(ans);
	while (p) {
		if (p & 1) {
			ans = ans*A;
		}
		A = A*A;
		p >>= 1;
	}
	return ans;
}

long long mu(long long a, long long p){
	long long ans=1;
	while (p) {
		if (p & 1) {
			ans = (ans*a)%MOD;
		}
		a=(a*a)%MOD;
		p >>= 1;
	}
	return ans;
}
matrix Ngichdao(matrix A){
    matrix B;
    B.a[1][1]=B.a[2][2]=1;
    B.a[1][1]=MOD-A.a[2][2];
    B.a[1][2]=A.a[1][2];
    long long k=(A.a[1][2]*A.a[2][1]-A.a[1][1]*A.a[2][2])%MOD;
    long long k1=(A.a[2][2]*k)%MOD;
    B.a[2][1]=(A.a[2][1]*A.a[2][2])%MOD;
    B.a[2][2]=(k-A.a[2][1]*B.a[1][2])%MOD;
	while (B.a[2][2] < 0) B.a[2][2] += MOD;
    B.a[1][1]=(B.a[1][1]*mu(k,MOD-2))%MOD;
    B.a[1][2]=(B.a[1][2]*mu(k,MOD-2))%MOD;
    B.a[2][1]=(B.a[2][1]*mu(k1,MOD-2))%MOD;
    B.a[2][2]=(B.a[2][2]*mu(k1,MOD-2))%MOD;
    return B;
}

matrix Sub(matrix A, matrix B){
    matrix S;
    S.a[1][1]=A.a[1][1]-B.a[1][1]; S.a[1][1] %= MOD; while (S.a[1][1] < 0) S.a[1][1] += MOD;
    S.a[2][1]=A.a[2][1]-B.a[2][1]; S.a[2][1] %= MOD; while (S.a[2][1] < 0) S.a[2][1] += MOD;
    S.a[1][2]=A.a[1][2]-B.a[1][2]; S.a[1][2] %= MOD; while (S.a[1][2] < 0) S.a[1][2] += MOD;
    S.a[2][2]=A.a[2][2]-B.a[2][2]; S.a[2][2] %= MOD; while (S.a[2][2] < 0) S.a[2][2] += MOD;
    return S;
}
matrix Add(matrix A, matrix B){
	matrix S;
    S.a[1][1]=A.a[1][1]+B.a[1][1]; S.a[1][1] %= MOD; while (S.a[1][1] < 0) S.a[1][1] += MOD;
    S.a[2][1]=A.a[2][1]+B.a[2][1]; S.a[2][1] %= MOD; while (S.a[2][1] < 0) S.a[2][1] += MOD;
    S.a[1][2]=A.a[1][2]+B.a[1][2]; S.a[1][2] %= MOD; while (S.a[1][2] < 0) S.a[1][2] += MOD;
    S.a[2][2]=A.a[2][2]+B.a[2][2]; S.a[2][2] %= MOD; while (S.a[2][2] < 0) S.a[2][2] += MOD;
    return S;
}
long long L,R,K;
int t,d=0;
int main(int argc, char const *argv[])
{
	cin>>t;
	while(t--){
		d++;
		cin>>L>>R>>K;
		matrix A, I, B;
		B.a[1][1]=B.a[2][2]=1;
		A.a[2][1] = 1;
		A.a[2][2] = 2;
		I.a[1][2] = I.a[2][1] = I.a[2][2] = 1;
 		if(L%K==0) L/=K;
  		else L=1+L/K;
  		R=(R/K)*K;
  		L*=K;
  		matrix tu,mau;
  		tu=Sub(pow_(I,R+K),pow_(I,L));
  		mau=Sub(pow_(I,K),B);
  		mau=Ngichdao(mau);
  		tu=tu*mau;
  		A=A*tu;
  		cout<<"Case "<<d<<": ";
  		if(A.a[2][1]>=0) cout<<A.a[2][1];
  		else cout<<A.a[2][1]+MOD;
  		cout<<endl;
	}
	return 0;
}
