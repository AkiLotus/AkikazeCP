#include <bits/stdc++.h>

using namespace std;

unsigned long long  lehman_simple(unsigned long long  n) {
    unsigned long long  n_1_3 = (unsigned long long ) ceil(pow(n, 1.0/3.0));
	double n_1_6 = pow(n, 1.0/6.0);
	unsigned long long  ub_d = max(n_1_3, (unsigned long long ) 19);
	for(unsigned long long  d=2; d<=ub_d; d++)
		if(n % d == 0) return d;
	for(unsigned long long  k=1; k<=n_1_3; k++) {
		unsigned long long  lb = ceil(2*sqrt(k)*sqrt(n));
		unsigned long long  ub = floor(2*sqrt(k)*sqrt(n) + n_1_6/(4*sqrt(k)));
		for(unsigned long long  a=lb; a<=ub; a++) {
			unsigned long long  delta = a*a - 4*k*n;
			unsigned long long  b = floor(sqrt(delta));
			if(b*b == delta) {
				return __gcd(a+b, n);
			}
		}
	}
	return n;
}

void lehman(unsigned long long  n, unsigned long long & p, unsigned long long & k, unsigned long long & m) { // Factor n == p^k * m, with p prime, k maximal for p
	m = n;
	do {
		p = m;
		m = lehman_simple(p);
	} while(m != p);
	k = 0;
	while(n % p == 0) {
		n /= p;
		++k;
	}
	m = n;
}

vector<unsigned long long> factory_prime(unsigned long long n) {
    vector <unsigned long long> vt;
    unsigned long long  p, k, m;
    lehman(n, p, k, m);
    for (int i = 1; i <= k; ++i) {
        vt.push_back(p);
    }
    while(m != 1) {
        lehman(m, p, k, m);
        for (int i = 1; i <= k; ++i) {
            vt.push_back(p);
        }
    }

    return vt;
}

int main() {
	unsigned long long  n;
	cin >> n;
    vector<unsigned long long> vt = factory_prime(n);
    cout << vt.size() << endl;
    for (int i = 0; i < vt.size(); i++) cout << vt[i] << " ";
}

