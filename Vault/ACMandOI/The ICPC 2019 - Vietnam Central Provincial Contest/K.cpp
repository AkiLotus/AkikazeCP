#include <bits/stdc++.h>

using namespace std;

int a[1000006], phi[1000006];
int N = 1000006;



int digits(int x) {
	int tmp = 0;
	while(x) {
		tmp++;
		x /= 10;
	}
	return tmp;
}

main () {
	//preprocess
	for (int i = 1; i < N; i++) phi[i] = i;
	for (int i = 2; i < N; i++) {
		if (phi[i] == i) {
			for (int j = 2*i; j < N; j += i) 
			phi[j] = phi[j] - phi[j]/i; 
		}
	}
	for (int i = 2; i < N; i++) phi[i] -= (phi[i] == i);
	
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i < N; i++) {
		int check = a[i-1]*a[i-digits(i)]*a[i-phi[i]];
		a[i] = 1 - check;	
	}
//	for (int i = 0; i < 20; i++) 
//		cout <<i << ' ' << (a[i] ? "N\n" : "P\n");
	//process
	int t;
	cin >> t;
	while (t--) {
		int u;
		cin >> u;
		cout << (a[u] ? "BACH\n" : "KHOA\n"); 
	}
}
