#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int p1 = 0, p2 = 0;
    if (k != 0) p1 = min(n-k, 1);
    if (n == 1 && k == 0) p2 = 0;
    else if ((n % 2 == 0 && k * 2 >= n) || (n % 2 == 1 && k * 2 + 1 >= n)) p2 = n - k;
    else p2 = min(n-k, 2*k);
    cout << p1 << " " << p2;
    return 0;
}
