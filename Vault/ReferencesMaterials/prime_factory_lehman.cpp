#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define fi first
#define se second
#define ll long long

vector <uint64_t> find_prime_divisors_lehman(uint64_t n) {
    vector<uint64_t> divisors;
    uint64_t sqrt3_n_up  = ceil(pow((long double)n, (long double) 1.0 / 3)) + 2;
    uint64_t m = 2;
    while (m * m <= n && m < sqrt3_n_up) {
        while (n % m == 0) {
            divisors.push_back(m);
            n /= m;
        }
        m++;
    }
    if (m * m > n) {
        if (n != 1) {
            divisors.push_back(n);
            return divisors;
        }
    }

    long double sqrt6_n = pow((long double)n, (long double) 1.0 / 6);
    long double sqrt_n = sqrt((long double)n);
    for (int k = 1; k < sqrt3_n_up; k++) {
        long double sqrt_k = sqrt((long double)k);
        uint64_t sqrt_4nk = ceil(2 * sqrt_k * sqrt_n) + 2;

        uint64_t diff = sqrt_4nk * sqrt_4nk - 4 * k * n;
        while (diff >= 2 * sqrt_4nk - 1) {
            diff = diff - 2 * sqrt_4nk + 1;
            --sqrt_4nk;
        }

        int max_d = ceil(sqrt6_n / (4 * sqrt_k)) + 3;
        for (int d = 0; d < max_d; ++d) {
            uint64_t a = sqrt_4nk + d;
            uint64_t b = round(sqrt((long double)diff));
            if (b * b == diff) {
                uint64_t d1 = __gcd(a + b, n);
                uint64_t d2 = __gcd(a - b, n);
                if (1 < d1 && d1 < n || 1 < d2 && d2 < n) {
                    uint64_t p = (1 < d1 && d1 < n) ? d1: d2;
                    divisors.push_back(p);
                    divisors.push_back(n / p);
                    return divisors;
                }
            }
            diff += 2 * a + 1;
        }
    }
    divisors.push_back(n);
    return divisors;
}

int main() {
    uint64_t n;
    cin >> n;
    vector <uint64_t> divisors = find_prime_divisors_lehman(n);
    cout << divisors.size() << endl;
    for (int i = 0; i < divisors.size(); i++) {
        cout << divisors[i]<< " ";
    }
}
