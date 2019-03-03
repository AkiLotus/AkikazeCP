#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void swap(long long &m, long long &n) {
    long long tmp = m;
    m = n; n = tmp;
}

long long gcd(long long a, long long b) {
    if (a < b) swap(a, b);
    while (true) {
        if (a % b == 0) return b;
        a %= b;
        swap(a, b);
    }
}

long long solve(long long &y, long long g, vector<long long> prime, vector<long long> exp) {
    long long tmpG = g;
    for (long long i=2; i<=sqrt(g); i++) {
        if (g % i == 0) {
            long long ite = find(prime.begin(), prime.end(), i) - prime.begin();
            while (g % i == 0) {
                exp[ite]--;
                g /= i;
            }
            if (exp[ite] == 0) {
                prime.erase(prime.begin()+ite);
                exp.erase(exp.begin()+ite);
            }
        }
    }
    if (g != 1) {
        long long ite = find(prime.begin(), prime.end(), g) - prime.begin();
        if (exp[ite] == 1) {
            prime.erase(prime.begin()+ite);
            exp.erase(exp.begin()+ite);
        }
        else exp[ite]--;
    }
    long long ans = 8952479449237;
    for (long long i=0; i<prime.size(); i++) {
        if ((y / tmpG) % prime[i] != 0) ans = min(ans, (y / tmpG) % prime[i]);
    }
    y -= ans * tmpG;
    return ans;
}

int main() {
    long long x, y;
    vector<long long> prime;
    vector<long long> exp;
    cin >> x >> y;
    long long tmpX = x;
    for (long long i=2; i<=sqrt(tmpX); i++) {
        if (tmpX % i == 0) {
            prime.push_back(i);
            exp.push_back(0);
            while (tmpX % i == 0) {
                tmpX /= i;
                exp[exp.size()-1]++;
            }
        }
    }
    if (tmpX != 1) {
        prime.push_back(tmpX);
        exp.push_back(1);
    }
    long long ans = 0;
    while (y != 0 && y % x != 0 && x % y != 0) {
        long long g = gcd(x, y);
        long long tmp = solve(y, g, prime, exp);
        ans += tmp;
    }
    if (y == 0) ans += 0;
    else if (y % x == 0) ans += y / x;
    else if (x % y == 0) ans += 1;
    cout << ans;
    return 0;
}
