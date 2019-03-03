#include <bits/stdc++.h>
#define LL long long
using namespace std;

vector<LL> ke[100005];
vector<LL> ce[100005];
LL pa[100005];
LL dx[100005];

LL N , M , alpha;

LL mi , ma ;

LL cnt ;

void readf(){
    cin >> N >> M >> alpha ;
	mi = LLONG_MAX ;
	ma = LLONG_MIN;
    for (LL i = 1; i<= M; i++){

		LL u,v,c;
		cin >> u >> v >> c;
		ke[u].push_back(v);
		ce[u].push_back(c);
		ke[v].push_back(u);
		ce[v].push_back(c);
		mi = min(mi,c);
		ma = max(ma,c);
	}
}

void dfs(LL g){
    queue <int> q;
    q.push(1);
    dx[1] = 0;
	while (q.size()){
        int u = q.front();
        q.pop();
        for (int i = 0 ; i<ke[u].size();  i++){
			int v = ke[u][i] ;
			int c = ce[u][i] ;
			if (c>g) continue ;
            if (dx[v] == -1 ){
                q.push(v);
                dx[v] = dx[u] + 1;
            }
			else{
				cnt = min(cnt , abs(dx[u] - dx[v]) + 1);
			}
        }
	}
}

LL check (LL g){
	cnt = M+1;
    for (LL i = 1; i<=N; i++) dx[i] = -1;
    for (int i = 1; i<=N; i++) pa[i] = 0;
    dfs(g);
    //cout << g << ' ' << cnt <<endl;
	return cnt ;
}

void solve(){
	LL ans = -1;
	LL d = mi ;
	LL c=  ma;
	while (d<=c){
		LL g = (d+c) / 2;
		LL tmp = check(g);
        if (check(g)!=M+1){
			ans = g*g + check(g)*alpha ;
            c = g-1;
        }
        else{
			d = g+1;
        }
	}
	if (ans == -1){
		cout << "Poor girl" <<endl;
	}
	else cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	readf();
	solve();
}
