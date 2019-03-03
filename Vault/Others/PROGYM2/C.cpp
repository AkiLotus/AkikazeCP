#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	ll N, M;
	queue<ll> Q;
	cin >> N;
	vector<bool> visited(200009, false);
	vector<ll> k(N);
    for (ll i=0; i<N; i++) {
	    cin >> k[i];
	    Q.push(k[i]); visited[k[i]] = true;
	}
	cin >> M;
	vector<ll> d(M); for (ll i=0; i<M; i++) cin >> d[i];
	while (!Q.empty()) {
        ll z = Q.front(); Q.pop();
        for (ll i=0; i<N; i++) {
            if (z+k[i] > 200000) continue;
            if (visited[z+k[i]]) continue;
            visited[z+k[i]] = true;
        }
	}
	ll ans = 0;
	for (ll i=0; i<M; i++) {
        if (visited[d[i]]) ans++;
	}
    cout << ans;
	return 0;
}
