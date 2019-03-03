#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, ans = 0;
map<int, vector<string>> Map;

void Try(int id, int sum, int last, string s) {
    if (id == n) {
        if (Map[sum].empty()) ans++;
        Map[sum].push_back(s); return;
    }
    if (last >= 1) Try(id+1, sum+1, 1, s+"I");
    if (last >= 5) Try(id+1, sum+5, 5, s+"V");
    if (last >= 10) Try(id+1, sum+10, 10, s+"X");
    if (last >= 50) Try(id+1, sum+50, 50, s+"L");
}

int main() {
    cin >> n;
    Try(0, 0, 100, "");
    cout << ans << endl;
//    for (auto it=Map.begin(); it != Map.end(); it++) {
//        cout << it->first << ": ";
//        for (auto z: it->second) cout << z << " "; cout << endl;
//    }
    return 0;
}