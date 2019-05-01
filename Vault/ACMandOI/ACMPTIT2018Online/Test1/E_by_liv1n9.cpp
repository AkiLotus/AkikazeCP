#include <bits/stdc++.h>
using namespace std;

const int nn = 2e5 + 8;

int a[nn], r[nn], n;
vector<int> e[nn];
int t[nn];

void update(int i, int v) {
    for(; i <= n; i += i & -i) t[i] = max(t[i], v);
}

int get(int i) {
    int res = 0;
    for(; i; i -= i & -i) res = max(res, t[i]);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        r[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = -4; j <= 4; j++) {
            if (a[i] + j < 1 || a[i] + j > n) continue;
            e[i].push_back(r[a[i] + j]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> tmp;
        for (int j = 0; j < e[i].size(); j++) {
            int Max = get(e[i][j] - 1) + 1;
            tmp.push_back(Max);
            res = max(res, Max);
        }
        for (int j = 0; j < tmp.size(); j++) {
            update(e[i][j], tmp[j]);
        }
    }
    cout << res;
}