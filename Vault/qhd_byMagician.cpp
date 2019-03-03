#include <bits/stdc++.h>
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
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }

const long double PI = 2*acos(0.0);
const long double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = (LL) 1e18;
const LL MOD = 1000000007;
#define maxn 200005

/**
Với mỗi node a quản lý đoạn u --> v
a.cnt = SL xâu con của a chia hết cho 3
a.left[i] = SL xâu con của a bắt đầu từ u và chia 3 dư i
a.right[i] = SL xâu con của a kết thúc ở v và chia 3 dư i

Gộp p từ a và b, có 5 cách tạo ra xâu con chia hết cho 3
+) a.cnt
+) b.cnt
+) a.right[0] * b.left[0]
+) a.right[1] * b.left[2]
+) a.right[2] * b.left[1]
*/

struct node{
    int left[3], right[3];
    LL sum, cnt;
    node () {
        left[0] = left[1] = left[2] = 0;
        right[0] = right[1] = right[2] = 0;
        sum = cnt = 0;
    }
};



int n, m;
string s;
node it[maxn*4];

node init_node(int val){
    node ans;
    ans.left[val] = ans.right[val] = 1;
    ans.sum = val;
    ans.cnt = 0;
    if(val%3 == 0) ans.cnt = 1;
    //if(i == 1) it[i].cnt = 1;
    return ans;
}

node merge(node a, node b){
    node ans;
    ans.cnt = a.cnt + b.cnt;
    FOR(i,0,2) FOR(j,0,2) if((i+j)%3 == 0)
        ans.cnt += a.right[i]*b.left[j];
    FOR(i,0,2){
        ans.left[i] = a.left[i] + b.left[(i-a.sum+3) % 3];
        ans.right[i] = b.right[i] + a.right[(i-b.sum+3) % 3];
    }
    ans.sum = (a.sum + b.sum) % 3;
    return ans;
}

void buildIT(int i, int l, int r){
    if (l == r){
        it[i] = init_node((s[l]-48) % 3);
        return;
    }
    int m = (l+r)/2;
    buildIT(i*2, l, m);
    buildIT(i*2+1, m+1, r);
    it[i] = merge(it[i*2], it[i*2+1]);
}


void update(int i, int l, int r, int u, int val){
    if(l > r || l > u || r < u) return;
    if(l == r){
        it[i] = init_node(val%3);
        return;
    }
    int mid = (l+r)/2, c1 = i*2, c2 = i*2+1;
    update(c1, l, mid, u, val);
    update(c2, mid+1, r, u, val);
    it[i] = merge(it[c1], it[c2]);
}

node get(int i, int l, int r, int u, int v){
    if (l > r || l > v || r < u) {
        node ans;
        return ans;
    }
    if (u <= l && r <= v) return it[i];
    int mid = (l + r) / 2;
    return merge(get(i*2, l, mid, u, v), get(i*2+1, mid+1, r, u, v)) ;
}

void solve(){

    int cmd, u, v, val;
    while(m--){
        cin >> cmd;
        if(cmd == 1){
            cin >> u >> val;
            update(1, 1, n, u, val);
        }
        else if(cmd == 2){
            cin >> u >> v;
            cout << get(1, 1, n, u, v).cnt << endl;
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
    buildIT(1, 1, n);
    solve();

    return 0;
}
