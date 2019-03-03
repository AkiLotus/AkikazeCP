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
	string input;
	cin >> input;
	string output = input;
	int spaceAdded = 0;
	int consCount = 0;
	bool monoletter = true;
	for (int i=0; i<input.size(); i++) {
        if (i > 0 && (input[i-1] != 'a' && input[i-1] != 'e' && input[i-1] != 'i' && input[i-1] != 'o' && input[i-1] != 'u') && input[i] != input[i-1]) monoletter = false;
        else if (input[i-1] == 'a' || input[i-1] == 'e' || input[i-1] == 'i' || input[i-1] == 'o' || input[i-1] == 'u') monoletter = true;
        if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u') consCount++;
        else consCount = 0;
        if (consCount >= 3 && !monoletter) {
            output.insert(i+spaceAdded, 1, ' ');
            spaceAdded++;
            consCount = 1;
            monoletter = true;
        }
	}
	cout << output;
	return 0;
}
