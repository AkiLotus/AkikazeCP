#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double, double> point;
typedef pair<point, double> circle;
#define X first
#define Y second

point operator + (point a, point b) { return point(a.X+b.X, a.Y+b.Y); }
point operator - (point a, point b) { return point(a.X-b.X, a.Y-b.Y); }
point operator / (point a, double x) { return point(a.X/x, a.Y/x); }
double abs(point a) { return sqrt(a.X*a.X+a.Y*a.Y); }

point center_from(double bx, double by, double cx, double cy) {
    double B=bx*bx+by*by, C=cx*cx+cy*cy, D=bx*cy-by*cx;
    return point((cy*B-by*C)/(2*D), (bx*C-cx*B)/(2*D));
}

circle circle_from(point A, point B, point C) {
    point I = center_from(B.X-A.X, B.Y-A.Y, C.X-A.X, C.Y-A.Y);
    return circle(I+A, abs(I));
}

const int N = 100005;
int n, x[N], y[N];
point a[N];

circle f(int n, vector<point> T) {
    if (T.size()==3 || n==0) {
        if (T.size()==0) return circle(point(0, 0), -1);
        if (T.size()==1) return circle(T[0], 0);
        if (T.size()==2) return circle((T[0]+T[1])/2, abs(T[0]-T[1])/2);
        return circle_from(T[0], T[1], T[2]);
    }
    random_shuffle(a+1, a+n+1);
    circle Result = f(0, T);
    for (int i=1; i<=n; i++)
    if (abs(Result.X - a[i]) > Result.Y+1e-9) {
        T.push_back(a[i]);
        Result = f(i-1, T);
        T.pop_back();
    }
    return Result;
}

main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        a[i] = point(x[i], y[i]);
    }

    circle C = f(n, vector<point>());
    (cout << fixed).precision(2);
    cout << 2*C.Y << endl;
}

/**
Bài toán
Tìm đường tròn nhỏ nhất chứa tất cả các điểm cho trước.
Độ phức tạp
O(n)

Mô tả
Emo Welzl đưa ra một thuật toán dùng random như sau:
Gọi f(S, T) là đường tròn nhỏ nhất chứa tất cả các điểm trong tập S và T là tập hợp các điểm phải nằm trên đuờng tròn. Điều ta cần tìm là f(S0, {}) trong đó S0 là tất cả các điểm được cho, {} là tập rỗng.

Nếu T chứa ba điểm:
Trả về đường tròn đi qua ba điểm này.
Nếu S rỗng:
Nếu T chứa 0 điểm, trả về một đường tròn có bán kính âm (một đường tròn không chứa điểm nào).
Nếu T chứa 1 hoặc 2 điểm, trả về đường tròn bé nhất chứa các điểm này.
Ngược lại, tức là nếu T chứa 0, 1 hoặc 2 điểm, và S không rỗng:
Chọn một điểm I ngẫu nhiên trong S.
Nếu I nằm trong đường tròn f(S-{I}, T), trả về f(S-{I}, T).
Ngược lại, trả về f(S-{I}, T+{I}).

Nhờ việc chọn ngẫu nhiên điểm I trong S, thuật toán này chạy trong O(n).

Để giảm độ sâu của việc đệ quy (có thể lên đến O(n) nếu cài không tốt), tôi khử đệ quy như sau:
Gọi f(n, T) là đường tròn nhỏ nhất chứa tất cả các điểm a[1..n] và T là tập hợp các điểm phải nằm trên đuờng tròn. Điều ta cần tìm là f(n, {}) trong đó, {} là tập rỗng.

Vòng for trong hàm hoạt động như sau:

Result = f(0, T)
For i từ 1 đến n:
Tóm tắt: Với mỗi i, ta sẽ tính f(i, T) dựa vào Result (hay chính là f(i-1, T)). Kết quả của f(i, T) sẽ đựoc lưu trở lại vào biến Result. Sau khi vòng for kết thúc, Result chính là f(n, T).
Nếu Result chứa a[i], ta giữ nguyên Result.
Ngược lại, gán Result = f(i-1, T+{a[i]})
**/
