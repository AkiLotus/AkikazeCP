#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;

ll M, N;
vector<ll> adj[11111];
bitset<11111> visited;
bitset<11111> chosen;

int main() {
	cin >> N >> M;
	while (M--) {
        ll x, y; cin >> x >> y;
        adj[x].push_back(y);
	}
	for (ll i=0; i<N; i++) {

	}
	cout << "Yes";
	return 0;
}
