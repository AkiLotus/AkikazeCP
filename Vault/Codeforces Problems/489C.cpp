#include <iostream>
#include <string>
using namespace std;

int main() {
	int m, s;
	string stringmin, stringmax;
	cin >> m >> s;
	int tmp = s;
	if (tmp > 9*m) {
		stringmin = "-1";
		stringmax = "-1";
	}
	if (tmp == 0) {
		if (m == 1) {
			stringmin = "0";
			stringmax = "0";
		}
		else {
			stringmin = "-1";
			stringmax = "-1";
		}
	}
	if (tmp <= 9*m-17 && tmp > 0) {
		stringmin = "10";
		tmp--;
		while (tmp >= 9) {
			stringmin.insert(2, 1, '9');
			tmp -= 9;
		}
		stringmin.insert(2, 1, char(tmp+48));
		int t = m - stringmin.size();
		stringmin.insert(2, t, '0');
	}
	if (tmp > 9*m-17 && tmp <= 9*m) {
		while (tmp >= 9) {
			stringmin.insert(stringmin.begin(), '9');
			tmp -= 9;
		}
		if (tmp != 0) {
			stringmin.insert(stringmin.begin(), char(tmp+48));
		}
	}
	tmp = s;
	if (tmp <= 9*m && tmp > 0) {
		while (tmp >= 9) {
			stringmax.insert(stringmax.end(), '9');
			tmp -= 9;
		}
		if (tmp != 0) {
			stringmax.insert(stringmax.end(), char(tmp+48));
		}
		int t = m - stringmax.size();
		stringmax.insert(stringmax.end(), t, '0');
	}
	cout << stringmin << " " << stringmax;
	return 0;
}
