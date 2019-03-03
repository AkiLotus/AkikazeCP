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

bool active[26];

int main() {
	int n, k;
	string guest;
	cin >> n >> k >> guest;
	int last[26];
	int ac = 0;
	for (int i=0; i<26; i++) last[i] = -1;
	for (int i=0; i<n; i++) last[guest[i]-'A'] = i;
	bool valid = false;
	for (int i=0; i<n; i++) {
        if (!active[guest[i]-'A']) ac++;
        active[guest[i]-'A'] = true;
        if (last[guest[i-1]-'A'] == i-1) {
            active[guest[i-1]-'A'] = false;
            ac--;
        }
        if (ac > k) {
            valid = true;
            break;
        }
	}
	if (valid) cout << "YES";
	else cout << "NO";
	return 0;
}
