#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define ZERO 1e-6
struct P
{
    double x, y;
};
double ans;

double dis(P a, P b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void getcross(P a, P b, P c )
{
    double a1 = b.y - a.y, b1 = a.x - b.x, c1 = a.x * b.y - b.x * a.y;
    double a2 = d.y - c.y, b2 = c.x - d.x, c2 = c.x * d.y - d.x * c.y;
    if(fabs(a1 * b2 - a2 * b1) < ZERO) return ;
    P p;
    p.y = (a2 * c1 - a1 * c2) / (a2 * b1 - a1 * b2);
    p.x = (b2 * c1 - b1 * c2) / (a1 * b2 - a2 * b1);
    ans = min(ans, dis(a, p) + dis(b, p) + dis(c, p) );
}

int main()
{
    P a, b, c, d;

    scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) ;
        ans = 1e8;

        ans = min(ans, dis(b, a) + dis(c, a) );
        ans = min(ans, dis(a, b) + dis(c, b) );
        ans = min(ans, dis(a, c) + dis(b, c) );
        getcross(a, b, c);
        getcross(a, c, b);
        printf("%.4f\n", ans);

    return 0;
}
