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
	string z;
	int cas = 0;
	cin >> z;
	while (z != "#") {
        cout << "Case " << ++cas << ": ";
        if (z == "HELLO") cout << "ENGLISH\n";
        else if (z == "HOLA") cout << "SPANISH\n";
        else if (z == "HALLO") cout << "GERMAN\n";
        else if (z == "BONJOUR") cout << "FRENCH\n";
        else if (z == "CIAO") cout << "ITALIAN\n";
        else if (z == "ZDRAVSTVUJTE") cout << "RUSSIAN\n";
        else cout << "UNKNOWN\n";
        cin >> z;
	}
	return 0;
}
