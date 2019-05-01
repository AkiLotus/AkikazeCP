#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

/**
Bài toán
Cho các điểm trên mặt phẳng, tìm bao lồi và tính diện tích của bao lồi
Độ phức tạp :
O(n log n)
Sắp xếp điểm theo góc : O(n log n)
Tìm bao lồi sau khi sắp xếp điểm : O(n)
**/

const int N = 20000;

struct Point {
    long long x, y;
    bool operator < (const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
    long long cross(const Point &p, const Point &q) const { return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x); }
} p[N], poly[N];

int n;

void enter() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%lld%lld", &p[i].x, &p[i].y);
}

long long size(Point poly[], int k) {
    long long S = (poly[k-1].x - poly[0].x) * (poly[k-1].y + poly[0].y);
    for(int i = 1; i < k; ++i)
        S += (poly[i-1].x - poly[i].x) * (poly[i-1].y + poly[i].y);
    return S;
    printf("%lld\n", S);
}

void solve() {
    sort(p, p+n); int k = 0;
    for(int i = 0; i < n; ++i) {
        while(k >= 2 && poly[k-2].cross(poly[k-1], p[i]) <= 0) --k;
        poly[k++] = p[i];
    }
    for(int i = n-2, t = k+1; i >= 0; --i) {
        while(k >= t && poly[k-2].cross(poly[k-1], p[i]) <= 0) --k;
        poly[k++] = p[i];
    }
    printf("%lld\n", size(poly, k));
}

int main() {
    enter();
    solve();
    return 0;
}
