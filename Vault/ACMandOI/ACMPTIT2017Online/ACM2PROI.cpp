#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, p, res = 0;
vector<int> adjacency[1001];
bool visited[1001] = {false};
vector<int> tmp;
vector<int> prime(1);

bool isPrime (int z) {
	for (int i=3; i<=sqrt(z); i+=2)
		if (z % i == 0) return false;
	return true;
}

void bfs(int z) {
	for (int i=0; i<adjacency[z].size(); i++) {
		if (!visited[adjacency[z][i]]) {
			visited[adjacency[z][i]] = true;
			bfs(adjacency[z][i]);
		}
	}
}

int main() {
	prime[0] = 2;
	for (int i=3; i<1001; i+=2)
		if (isPrime(i)) prime.push_back(i);
	int t, cas = 0;
	cin >> t;
	while (t-- > 0) {
		for (int i=0; i<1001; i++) {
			adjacency[i].clear();
			visited[i] = false;
		}
		cas++; res = 0;
		cout << "Case #" << cas << ": ";
		cin >> a >> b >> p;
		int primebegin = lower_bound(prime.begin(), prime.end(), p) - prime.begin();
		int primeend = upper_bound(prime.begin(), prime.end(), b) - prime.begin();
		for (int i=primebegin; i<primeend; i++) {
			tmp.clear();
			int zzz = prime[i] - a % prime[i];
			if (zzz == prime[i]) zzz = 0;
			for (int j=a+zzz; j<=b; j+=prime[i]) tmp.push_back(j);
			for (int j=0; j<tmp.size(); j++) {
				for (int k=0; k<tmp.size(); k++) {
					if (j != k) {
						adjacency[tmp[j]].push_back(tmp[k]);
						adjacency[tmp[k]].push_back(tmp[j]);
					}
				}
			}
		}
		for (int i=a; i<=b; i++) {
			if (!visited[i]) {
				res++;
				bfs(i);
			}
		}
		cout << res << endl;
	}
	return 0;
}
