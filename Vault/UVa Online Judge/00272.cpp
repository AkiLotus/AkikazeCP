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
	string tmp;
	int stat = 0;
	while (getline(cin, tmp)) {
        for (int i=0; i<tmp.size(); i++) {
            if (tmp[i] == '\"') {
                if (stat == 0) cout << "``";
                else cout << "\'\'";
                stat = (stat + 1) % 2;
            }
            else cout << tmp[i];
        }
        cout << endl;
	}
	return 0;
}
