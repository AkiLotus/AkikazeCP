#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n, m, k; vector<pair<int, int>> a;

void Input() {
	cin >> n >> m >> k; a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
}

void Solve() {
    sort(a.rbegin(), a.rend());
    vector<bool> contained(n, false);
    long long sum = 0; vector<int> PartitionList;
    for (int i=0; i<m*k; i++) {
        int id = a[i].second;
        contained[id] = true;
        sum += a[i].first;
    }
    int curseg = 0;
    for (int i=0; i<n; i++) {
        curseg += contained[i];
        if (curseg == m) {curseg = 0; PartitionList.push_back(i+1);}
        if (PartitionList.size() == k-1) break;
    }
    cout << sum << endl;
    for (auto x: PartitionList) cout << x << " "; cout << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}
