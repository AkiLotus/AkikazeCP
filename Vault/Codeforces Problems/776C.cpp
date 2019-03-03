#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const long long Mod = 1000000007LL;

int n, k; vector<int> a;
vector<long long> Powers;

void CalculatePowers() {
    if (k == 1) {Powers.push_back(1); return;}
    if (k == -1) {Powers.push_back(-1); Powers.push_back(1); return;}
    long long Mul = 1;
    while (abs(Mul) <= 1e15) {
        Powers.push_back(Mul);
        Mul *= k;
    }
}

void Input() {
	cin >> n >> k; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
    CalculatePowers();
    map<long long, int> Prefixcnt;
    long long sum = 0; Prefixcnt[0]++;
    long long ans = 0;
    for (auto val: a) {
        sum += val;
        for (auto demanding: Powers) {
            long long neededPrefix = sum - demanding;
            if (Prefixcnt.find(neededPrefix) == Prefixcnt.end()) continue;
            ans += Prefixcnt[neededPrefix];
        }
        Prefixcnt[sum]++;
    }
    cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
