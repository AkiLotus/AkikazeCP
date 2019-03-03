#include <iostream>
using namespace std;

int main() {
    string s;
    int k;
    int cc[26];
    cin >> s >> k;
    for (int i=0; i<26; i++) cc[i] = 0;
    if (s.size() < k) {
        cout << "impossible";
    }
    else {
        for (int i=0; i<s.size(); i++) {
            cc[int(s[i])-97]++;
        }
        int num = 0;
        for (int i=0; i<26; i++) {
            if (cc[i] > 0) num++;
        }
        if (num >= k) cout << 0;
        else cout << k - num;
    }
	return 0;
}
