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
	int t, donation = 0;
	cin >> t;
	while (t-- > 0) {
        string cmd;
        cin >> cmd;
        if (cmd == "donate") {
            int par; cin >> par;
            donation += par;
        }
        else if (cmd == "report") cout << donation << endl;
	}
	return 0;
}
