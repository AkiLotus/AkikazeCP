#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<double,int>II;
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

const double PI = 2*acos(0.0);
const double eps = 1e-6;
const int infi = 1e9;
const LL Linfi = 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 1000005


int found = 0;
LL F2, F3, F4, L, R;

LL power(LL a, LL p){
    if(p == 0) return 1;
    if(p == 1) return a;
    LL ans = power(a, p/2);
    ans = (ans*ans) % MOD;
    if(p%2) ans = (ans*a) % MOD;
    return ans;
}

int findNum(long double x){
    LL a = x;
    FOR(i,a-2,a+2) if(abs(i-x) < eps) return i;
    return -1;
}



void findABC(LL &a, LL &b, LL &c){
    for(a = 1; a <= 5000; a++) {
        if(1LL*a*a > F2) break;
        LL x = F2 - a*a;
        LL z = F4 - 1LL*a*a*a*a;
        if(x < 0 || z < 0) break;
        double tmp =  (2*x)*(2*x) - 4*2*(x*x-z);;
        LL delta = (2*x)*(2*x) - 4*2*(x*x-z);

        if(delta > 0){
            long double b1 = (1.0*(2*x) + sqrt(tmp)) / 4;
            long double b2 = (1.0*(2*x) - sqrt(delta)) / 4;
            if(b1 < 0) continue;
            b = findNum(sqrt(b1));
            if(b == -1) continue;
            c = findNum(sqrt(x-b*b));
            if(c == -1) continue;
            //cout << b <<  " " << c << endl;
            LL F22 = 1LL*a*a + 1LL*b*b + 1LL*c*c;
            LL F33 = 1LL*a*a*a + 1LL*b*b*b + 1LL*c*c*c;
            LL F44 = 1LL*a*a*a*a + 1LL*b*b*b*b + 1LL*c*c*c*c;
            if(F22 == F2 && F33 == F3 && F44 == F4) {
                found = 1;
                return;
            }
        }

    }
}

void solve(){
    found = 0;
    LL a, b, c;
    findABC(a, b, c);
    //if(found) cout << a << " " << b << " " << c << endl;
    LL ans = 0, tmp;
    if(a == 1) ans = R-L+1;
    else{
        tmp = (power(a, R+1) - power(a, L) + MOD) % MOD;
        tmp = (tmp * power(a-1, MOD-2)) % MOD;
        ans = (ans + tmp) % MOD;
    }

    if(b == 1) ans += R-L+1;
    else{
         tmp = (power(b, R+1) - power(b, L) + MOD) % MOD;
        tmp = (tmp * power(b-1, MOD-2)) % MOD;
        ans = (ans + tmp) % MOD;
    }

    if(c == 1) ans += R-L+1;
    else{
        tmp = (power(c, R+1) - power(c, L) + MOD) % MOD;
        tmp = (tmp * power(c-1, MOD-2)) % MOD;
        ans = (ans + tmp) % MOD;
    }


    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    while(sotest--){
        cin >> F2 >> F3 >> F4 >> L >> R;
        solve();
    }


    return 0;
}
