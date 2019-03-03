#include <bits/stdc++.h>

#define MOD  1000000007
#define BASE 100007
#define LL long long
using namespace std;

int hp, wp, hm, wm;
int p[4003][4003], t[4003][4003];
LL M[4003][4003] , H[4003][4003];
LL powH[4003];
LL powW[4003];
LL hash_P;

void readf(){
	cin >> hp >> wp >> hm >> wm ;
	for (int i = 0; i< hp; i++){
		for (int j = 0; j<wp; j++){
			char c;
			cin >> c ;
			p[i][j] = (c=='x');
		}
	}
	for (int i = 0; i< hm; i++){
		for (int j = 0; j<wm; j++){
			char c;
			cin >> c ;
			t[i][j] = (c=='x');
		}
	}
}
void initPow(){
	powH[0] = 1;
  	for (int i = 1; i<=hp; i++)
    	powH[i] = (powH[i-1]*BASE) % MOD;
	powW[0] = 1;
  	for (int i = 1; i<=wp; i++)
    	powW[i] = (powW[i-1]*powH[hp]) % MOD;
}

void buildHashP(){
	hash_P = 0 ;
	for (int j = 0; j < wp; j++)
    	for (int i = 0; i < hp; i++) 
    	  hash_P = ((hash_P*BASE % MOD) + p[i][j]) % MOD;
}

void buildM() {
	for (int j = 0; j < wm; j++) {
    	LL hash = 0;
    	for (int i = 0; i < hp; i++)
      		hash = (hash + ((t[i][j]*powH[hp-i-1]) % MOD)) % MOD;
	    M[0][j] = hash;
	    for (int i = hp; i < hm; i++) {
	      	hash = (hash + MOD - ((t[i-hp][j]*powH[hp-1]) % MOD)) % MOD;
	        hash = (hash*BASE)%MOD;
		  	hash = (hash+t[i][j]) % MOD;
	      	M[i-hp+1][j] = hash;
	    }
  	}
}

void buildH() {
	buildM();
  	for (int i = 0; i < hm-hp+1; i++) {
    	LL hash = 0;
    	for (int j = 0; j < wp; j++)
      		hash = (hash+(M[i][j]*powW[wp-j-1] % MOD)) % MOD;
    		H[i][0] = hash;
  	}
  
  	for (int j = 1; j < wm-wp+1; j++){
    	for (int i = 0; i < hm-hp+1; i++) {
      		H[i][j] = (H[i][j-1] + MOD - (M[i][j-1]*powW[wp-1] % MOD)) % MOD;
      		H[i][j] = (H[i][j] * powW[1]) % MOD;
      		H[i][j] = (H[i][j] + M[i][j+wp-1]) % MOD;
    	}
    }
}
void solve(){
	initPow();
  	buildHashP();
	buildH();
  	int ans = 0;
  	for (int i = 0; i < hm; i++) 
    	for (int j = 0; j < wm; j++)
      		if (H[i][j] == hash_P) 
				ans++;
	cout << ans ;
}
int main() {
	ios_base::sync_with_stdio(0);
	readf();
	solve();
}
