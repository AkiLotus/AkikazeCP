#include <iostream>
#include <cmath>
using namespace std;
 
int st, fn;
bool p[16384];
bool inq[16384] = {false};
 
void readf() {
	cin >> st >> fn;
}
 
void init() {
	for (int i=1000; i<10000; i++) {
		p[i] = true;
		if (i % 2 == 0) {
			p[i] = false;
			continue;
		}
		for (int j=3; j<=sqrt(i); j+=2) {
			if (i % j == 0) {
				p[i] = false;
				break;
			}
		}
	}
}
 
int calculate (int u, int k, int t) {
	int x[5];
	int uu = u;
	for (int i=1; i<=4; i++) {
		x[i] = uu % 10;
		uu /= 10;
	}
	x[k] = t;
	return (x[1] + x[2] * 10 + x[3] * 100 + x[4] * 1000);
}
 
void broaden() {
	int Q[16384], f = 1, l = 1;
	Q[1] = st;
	inq[st] = true;
	int d = 0;
	while (f <= l) {
		int ll = l;
		for (int i=f; i<=l; i++) {
			int u = Q[i];
			if (u == fn) {
				cout << d << endl;
				return;
			}
			for (int k=1; k<=4; k++) {
				for (int t=0; t<=9; t++) {
					int v = calculate(u, k, t);
					if (v >= 1000 && v < 10000 && !inq[v] && p[v]) {
						inq[v] = true;
						ll++;
						Q[ll] = v;
					}
				}
			}
		}
		f = l + 1;
		l = ll;
		d++;
	}
}
 
int main() {
	int t;
	init();
	cin >> t;
	while (t-- > 0) {
		for (int i=0; i<16384; i++) {
			inq[i] = false;
		}
		readf();
		broaden();
	}
} 