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
	int n; string s; int ans = 0;
	int cc[26];
	for (int i=0; i<26; i++) cc[i] = 0;
	cin >> n >> s;
	for (int i=0; i<n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            int tmp = 0;
            for (int i=0; i<26; i++) {
                if (cc[i] > 0) tmp++;
                cc[i] = 0;
            }
            ans = max(ans, tmp);
        }
        else cc[s[i]-'a']++;
	}
	int tmp = 0;
	for (int i=0; i<26; i++) {
        if (cc[i] > 0) tmp++;
        cc[i] = 0;
    }
    ans = max(ans, tmp);
	cout << ans;
	return 0;
}
