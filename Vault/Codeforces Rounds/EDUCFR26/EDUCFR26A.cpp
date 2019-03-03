#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    s += " ";
    int tmp = 0, ans = 0;
    for (int i=0; i<=n; i++) {
        if (s[i] == ' ') {
            ans = max(tmp, ans);
            tmp = 0;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') tmp++;
    }
    cout << ans;
    return 0;
}
