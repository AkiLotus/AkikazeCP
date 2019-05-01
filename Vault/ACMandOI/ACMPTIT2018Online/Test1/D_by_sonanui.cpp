#include <bits/stdc++.h>
using namespace std;

int count(string s, char c) {
	int pos;
	for (int i = 0; i < 52; i++) {
		if (s[i] == c) {
			pos = i;
			break;
		}
	}
	int cnt[26] = {0};
	for (int i = pos + 1; i < 52; i++) {
		if (s[i] == c) {
			break;
		}
		cnt[s[i] - 'A']++;
	}
	int res = 0;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 1) res++;
	}
	return res;
}

int main() {
	string s;
	cin >> s;
	int res = 0;
	for (char c = 'A'; c <= 'Z'; c++) {
		res += count(s, c);
	}
	cout << res/2;
}