#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int Max[4096][4096];

struct dir {
    int ll, rr, id;
    dir (int L, int R, int X)
        { ll=L, rr=R, id=X; }
    dir left() const
        { return dir(ll, (ll+rr)/2, id*2); }
    dir right() const
        { return dir((ll+rr)/2+1, rr, id*2+1); }
    inline bool irrelevant(int L, int R) const
        { return ll>R || L>rr || L>R; }
};

void maximize(int &a, int b)
    { a=max(a, b); }

void maximize(const dir &dx, const dir &dy, int x, int y, int k, bool only_y) {
    if (dx.irrelevant(x, x) || dy.irrelevant(y, y)) return;
    maximize(Max[dx.id][dy.id], k);
    if (!only_y && dx.ll != dx.rr) {
        maximize(dx.left(), dy, x, y, k, false);
        maximize(dx.right(), dy, x, y, k, false);
    }
    if (dy.ll != dy.rr) {
        maximize(dx, dy.left(), x, y, k, true);
        maximize(dx, dy.right(), x, y, k, true);
    }
}

int max_range(const dir &dx, const dir &dy, int lx, int rx, int ly, int ry) {
    if (dx.irrelevant(lx, rx) || dy.irrelevant(ly, ry)) return 0;
    if (lx<=dx.ll && dx.rr<=rx) {
        if (ly<=dy.ll && dy.rr<=ry) return Max[dx.id][dy.id];
        int Max1 = max_range(dx, dy.left(), lx, rx, ly, ry);
        int Max2 = max_range(dx, dy.right(), lx, rx, ly, ry);
        return max(Max1, Max2);
    } else {
        int Max1 = max_range(dx.left(), dy, lx, rx, ly, ry);
        int Max2 = max_range(dx.right(), dy, lx, rx, ly, ry);
        return max(Max1, Max2);
    }
}

const int M=100005, N=1003;
int m, k, x[M], y[M], z[M];

main() {
    scanf("%d%d", &m, &k);
    for (int i=1; i<=m; i++)
    scanf("%d%d%d", &x[i], &y[i], &z[i]);

    dir dx(0, N+N, 1), dy(0, N+N, 1);
    for (int i=m; i>=1; i--) {
        #define actual(x, y, k) x+y-k, x+y+k, x-y-k+N, x-y+k+N
        int F = max_range(dx, dy, actual(x[i], y[i], k)) + z[i];
        maximize(dx, dy, x[i]+y[i], x[i]-y[i]+N, F, false);
    }
    cout << max_range(dx, dy, actual(0, 0, k)) << endl;
}
