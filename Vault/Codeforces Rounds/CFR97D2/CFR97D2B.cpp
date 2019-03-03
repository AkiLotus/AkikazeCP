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

string toTertiary(long long z) {
    string res = "";
    while (z > 0) {
        char tmp = '0' + (z % 3);
        res.insert(0, 1, tmp);
        z /= 3;
    }
    return res;
}

int main() {
	long long a, c;
	cin >> a >> c;
	string ta = toTertiary(a);
	string tc = toTertiary(c);
	ta.insert(0, 20-ta.size(), '0');
	tc.insert(0, 20-tc.size(), '0');
	//cout << ta << endl << tc << endl;
	string res = "....................";
	for (long long i=0; i<20; i++) {
        long long z = tc[i] - ta[i];
        while (z < 0) z += 3;
        res[i] = '0' + z;
	}
	//cout << res << endl;
	long long ans = 0;
	for (long long i=0; i<20; i++) {
        ans *= 3;
        ans += (res[i] - '0');
	}
	cout << ans;
	return 0;
}
