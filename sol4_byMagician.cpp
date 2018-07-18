#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <ctime>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOD(i,a,b) for(int i=a;i>b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<int,int>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const long double eps = 1e-6;
const int infi = 1e9;
const LL Linfi = (LL) 9e18;
const LL MOD = 1000000007;
#define maxn 100005

int n, m;
string s;
int a[maxn], sum[maxn];

struct node{
    int it[3];
    int lazy;
    node(){}
    node(int _a, int _b, int _c, int _d){
        it[0] = _a;
        it[1] = _b;
        it[2] = _c;
        lazy = _d;
    }
};
node tree[maxn*8];

node merge(node a, node b){
    node ans = node(0,0,0,0);
    FOR(j,0,2) ans.it[j] = a.it[j] + b.it[j];
    return ans;
}

void build_it(int i, int l, int r){
    if(l == r){
        tree[i] = node(0,0,0,0);
        tree[i].it[sum[l]]++;
        return;
    }
    int mid = (l+r)>>1;
    build_it(2*i, l, mid);
    build_it(2*i+1, mid+1, r);
    tree[i] = merge(tree[i*2], tree[i*2+1]);
}

void xoay(int i, int cnt){
    FOR(k,1,cnt){
        swap(tree[i].it[2], tree[i].it[1]);
        swap(tree[i].it[1], tree[i].it[0]);
    }
}

void down(int i){
    xoay(i*2, tree[i*2].lazy);
    xoay(i*2+1, tree[i*2+1].lazy);
    tree[i*4].lazy = (tree[i*4].lazy + tree[i*2].lazy) % 3;
    tree[i*4+1].lazy = (tree[i*4+1].lazy + tree[i*2].lazy) % 3;
    tree[i*4+2].lazy = (tree[i*4+2].lazy + tree[i*2+1].lazy) % 3;
    tree[i*4+3].lazy = (tree[i*4+3].lazy + tree[i*2+1].lazy) % 3;
    tree[i*2].lazy = tree[i*2+1].lazy = 0;
}

void update(int i, int l, int r, int u, int v, int x){
    if(x == 0) return;
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        tree[i].lazy = (tree[i].lazy + x) % 3;
        xoay(i, tree[i].lazy);
        tree[i*2].lazy = (tree[i*2].lazy + tree[i].lazy) % 3;
        tree[i*2+1].lazy = (tree[i*2+1].lazy + tree[i].lazy) % 3;
        tree[i].lazy = 0;
        return;
    }
    int mid = (l+r)>>1;
    down(i);
    update(2*i, l, mid, u, v, x);
    update(2*i+1, mid+1, r, u, v, x);
    tree[i] = merge(tree[i*2], tree[i*2+1]);
}

node query(int i, int l, int r, int u, int v){
    if(l > v || r < u) {
        node tmp = node(0,0,0,0);
        return tmp;
    }
    if(l >= u && r <= v){
        return tree[i];
    }
    int mid = (l+r)>>1;
    down(i);
    node n1 = query(2*i, l, mid, u, v);
    node n2 = query(2*i+1, mid+1, r, u, v);
    return merge(n1, n2);
}

void solve(){
    FOR(i,1,n) a[i] = (s[i]-48) % 3;
    FOR(i,1,n) sum[i] = (sum[i-1] + a[i]) % 3;
    memset(add, 0, sizeof(add));
    build_it(1,0,n);
    //FOR(i,1,n) cout << sum[i] << " "; cout << endl;

    int cmd, u, v;
    FOR(i,1,m){
        cin >> cmd;
        if(cmd == 1){
            cin >> u >> v;
            v %= 3;
            int change = (v - a[u] + 3) % 3;
            update(1,0,n,u,n,change);
            a[u] = v;
        }
        else if(cmd == 2){
            cin >> u >> v;
            LL ans = 0;
            node tmp = query(1, 0, n, u-1, v);
            FOR(j,0,2) ans += 1LL*tmp.it[j]*(tmp.it[j]-1)/2;
            cout << ans << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    cin >> n >> m;
    cin >> s;
    s = '0' + s;


    solve();

    return 0;
}
