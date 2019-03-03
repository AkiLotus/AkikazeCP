#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define pii pair<int, int>
#define ppp pair<pii, pii>
#define data pair<ppp, int>

vector<int> adj[54321];
int N;

int main() {
    cin >> N;
    vector<data> a(N);
    vector<data> b(N);
    for (int i=0; i<N; i++) {
        int X, Y, W, H;
        cin >> X >> Y >> W >> H;
        pii p1 = make_pair(X, Y);
        pii p2 = make_pair(X+W, Y+H);
        ppp tmp1 = make_pair(p1, p2);
        ppp tmp2 = make_pair(p2, p1);
        a[i] = make_pair(tmp1, i);
        b[i] = make_pair(tmp2, i);
    }
    sort(a.begin(), a.end());
	return 0;
}
