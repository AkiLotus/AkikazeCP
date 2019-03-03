#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<int> a;
int bestt = 0, bestval = 1000000000;

void Input() {
	cin >> n; a.resize(n);
    for (auto &x: a) cin >> x;
}

void Solve() {
	for (int t=1; t<=200; t++) {
        int tmp = 0;
        for (int i=0; i<n; i++) {
            int z = min({abs(t-1 - a[i]), abs(t-0 - a[i]), abs(t+1 - a[i])});
            tmp += z;
        }
        if (tmp < bestval) {bestt = t; bestval = tmp;}
    }
    cout << bestt << " " << bestval << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/