#include <iostream>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	s += "0";
	string ans = "";
	int tmp = 0;
	for (int i=0; i<=n; i++) {
        if (s[i] == '0') {
            char c = char(tmp+48);
            ans += c;
            tmp = 0;
        }
        else tmp++;
	}
	cout << ans;
	return 0;
}
