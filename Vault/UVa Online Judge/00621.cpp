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
	int t;
	cin >> t;
	while (t-- > 0) {
        string p;
        cin >> p;
        if (p == "1" || p == "4" || p == "78") cout << "+\n";
        else if (p[p.size()-2] == '3' && p[p.size()-1] == '5') cout << "-\n";
        else if (p[0] == '9' && p[p.size()-1] == '4') cout << "*\n";
        else if (p[0] == '1' && p[1] == '9' && p[2] == '0') cout << "?\n";
	}
	return 0;
}
