#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int L, N, B;
vector<piii> Adj[10000];
vector<pii> Dijk[10000];
vector<bool> visited(10000, false);
int ans = -1;

bool custom (pii a, pii b) {
    if (a.first < b.first) return true;
    if (a.first == b.first && a.second > b.second) return true;
    return false;
}

int main() {
	cin >> L >> N >> B;
	while (N-- > 0) {
        int X, W, F, C;
        cin >> X >> W >> F >> C;
        piii tmp; tmp.first = X+W;
        pii tmp2; tmp2.first = F; tmp2.second = C;
        tmp.second = tmp2;
        Adj[X].push_back(tmp);
	}
	pii r; r.first = 0; r.second = 0; Dijk[0].push_back(r);
	for (int i=0; i<L; i++) {
        for (int j=0; j<Dijk[i].size(); j++) {
            pii tmp = Dijk[i][j];
            for (int k=0; k<Adj[i].size(); k++) {
                pii out = tmp;
                pii tmp2 = Adj[i][k].second;
                if (out.second + tmp2.second < B) {
                    out.first += tmp2.first; out.second += tmp2.second;
                    Dijk[Adj[i][k].first].push_back(out);
                }
            }
        }
        sort(Dijk[i].begin(), Dijk[i].end(), custom);
        for (int j=Dijk[i].size()-1; j>=0; j--) {
            for (int k=0; k<j; k++) {
                if (Dijk[i][j].first > Dijk[i][k].first && Dijk[i][j].second < Dijk[i][j].second) {
                    Dijk[i].erase(Dijk[i].begin()+k); k--; j--;
                }
            }
        }
	}
	if (Dijk[L].size() == 0) cout << "-1";
	else {
        for (int i=0; i<Dijk[L].size(); i++) {
            pii m = Dijk[L][i];
            ans = max(ans, m.first);
        }
        cout << ans;
	}
	return 0;
}
