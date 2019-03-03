#include <iostream>
using namespace std;

long long strtoll(string z) {
	long long result = 0, sign = 1, i = 0;
	if (z[0] == '-') {
		i = 1; sign = -1;
	}
	for (; i<z.size(); i++) {
		result *= 10;
		result += (z[i] - '0');
	}
	return result * sign;
}

int main() {
	int n, x;
	cin >> n >> x;
	int power = 131072;
    if (n == 1) cout << "YES\n" << x;
    else if (n == 2) {
        if (x == 0) cout << "NO";
        else cout << "YES\n" << 0 << " " << x;
    }
    else {
        cout << "YES\n";
        int tmpBitwise = 0;
        for (int i=1; i<=n-3; i++) {
            cout << i << " ";
            tmpBitwise = tmpBitwise ^ i;
        }
        if (tmpBitwise == x) cout << power << " " << 2*power << " " << (power ^ (power * 2));
        else cout << 0 << " " << power << " " << (power ^ x ^ tmpBitwise);
    }
	return 0;
}
