#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5;

int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];
int l[MAXN], r[MAXN];
string S;

bool sufCmp(int i, int j) {
    if (pos[i] != pos[j]) {
        return pos[i] < pos[j];
    }
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}
void buildSA() {
    N = S.length();
    for (int i = 0; i < N; i++) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap *= 2) {
        sort(sa, sa + N, sufCmp);
        for (int i = 0; i < N - 1; i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        for (int i = 0; i < N; i++) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}
void buildLCP() {
    for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1) {
        for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
        ++k;
        lcp[pos[i]] = k;
        if (k)--k;
    }
}

void getLeft() {
    stack<int> st;
    for (int i = 0; S[i]; i++) {
        l[i] = i;
        while (!st.empty() && lcp[i] <= lcp[st.top()]) {
            l[i] = l[st.top()];
            st.pop();
        }
        st.push(i);
    }
}

void getRight() {
    stack<int> st;
    for (int i = S.length() - 1; i >= 0; i--) {
        r[i] = i;
        while (!st.empty() && lcp[i] <= lcp[st.top()]) {
            r[i] = r[st.top()];
            st.pop();
        }
        st.push(i);
    }
}

int main() {
    cin >> S;
    buildSA();
    buildLCP();
    int n = S.length();
    ll res = n;
    getLeft();
    getRight();
    for (int i = 0; i < n; i++) {
        res = max(res, (ll)lcp[i] * (r[i] - l[i] + 2));
    }
    cout << res;
}
