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
	char start, finish;
	int times;
	cin >> start >> finish >> times;
	if (start == finish || (start == '^' && finish == 'v') || (start == 'v' && finish == '^') || (start == '<' && finish == '>') || (start == '>' && finish == '<')) {
        cout << "undefined";
	}
	else {
        if ((start == '^' && finish == '>') || (start == 'v' && finish == '<') || (start == '<' && finish == '^') || (start == '>' && finish == 'v')) {
            if (times % 4 == 1) cout << "cw";
            else cout << "ccw";
        }
        else if (times % 4 == 1) cout << "ccw";
        else cout << "cw";
	}
	return 0;
}
