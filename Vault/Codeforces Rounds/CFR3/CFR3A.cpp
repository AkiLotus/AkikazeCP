#include <iostream>
using namespace std;

typedef long long ll;

ll strtoll(string z) {
	ll result = 0, sign = 1, i = 0;
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
	string st, en;
	string mainPattern;
	cin >> st >> en;
	int x1 = st[0] - 'a' + 1, y1 = st[1] - '0';
	int x2 = en[0] - 'a' + 1, y2 = en[1] - '0';
	if (x1 == x2) {
        if (y1 > y2) {
            cout << y1 - y2 << endl;
            for (int i=0; i<y1-y2; i++) cout << "R\n";
        }
        else {
            cout << y2 - y1 << endl;
            for (int i=0; i<y2-y1; i++) cout << "L\n";
        }
	}
	else if (y1 == y2) {
        if (y1 > y2) {
            cout << x1 - x2 << endl;
            for (int i=0; i<x1-x2; i++) cout << "D\n";
        }
        else {
            cout << x2 - x1 << endl;
            for (int i=0; i<x2-x1; i++) cout << "U\n";
        }
	}
	else {

	}
	return 0;
}
