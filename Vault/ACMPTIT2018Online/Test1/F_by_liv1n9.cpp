#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nn = 1e5 + 8;

map<ll, ll> f;
string s[nn];
ll d[nn];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ll code = 0;
        for (int j = 0; s[i][j]; j++) {
            code = code * 28 + s[i][j] - 96;
        }
        f[code]++;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        ll code1 = 0;
        for (int j = 0; s[i][j]; j++) {
            code1 = code1 * 28 + s[i][j] - 96;
        }
        set<ll> st;
        for (int l = 0; s[i][l]; l++) {
            ll code2 = 0;
            for (int r = l; s[i][r]; r++) {
                code2 = code2 * 28 + s[i][r] - 96;
                st.insert(code2);
            }
        }
        for (set<ll>::iterator it = st.begin(); it != st.end(); it++) {
            res += f[*it] - (*it == code1);
        }
    }
    cout << res;
}