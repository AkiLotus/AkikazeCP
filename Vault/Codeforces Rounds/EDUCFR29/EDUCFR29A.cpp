#include <iostream>
#include <algorithm>
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
	string num; cin >> num;
	while (num[num.size()-1] == '0') num.erase(num.size()-1);
	string q = num; reverse(q.begin(), q.end());
	if (q == num) cout << "YES";
	else cout << "NO";
	return 0;
}
