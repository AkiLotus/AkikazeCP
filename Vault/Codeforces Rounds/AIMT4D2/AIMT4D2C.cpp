#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data {
    int x, y;
};

int n;
vector<data> a(100005);
vector<int> visited(100005);
std::vector<std::vector<int>> ans;
int Count = 0;

void DFS(int z) {
    if (visited[a[z].y] == -1) {
        visited[a[z].y] = visited[z];
        ans[visited[z]].push_back(a[z].y+1);
        DFS(a[z].y);
    }
}

bool dataSort(data a, data b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        visited[i] = -1;
        cin >> a[i].x;
        a[i].y = i;
    }
    vector<data> tmp(a.begin(), a.begin()+n);
    sort(tmp.begin(), tmp.end(), dataSort);
    for (int i=0; i<n; i++) {
        if (a[tmp[i].y].y == i) {
            vector<int> tmpV(1); tmpV[0] = i+1;
            ans.push_back(tmpV);
            visited[i] = Count;
            Count++;
        }
        else a[tmp[i].y].y = i;
    }
    for (int i=0; i<n; i++) {
        if (visited[i] != -1) continue;
        visited[i] = Count; Count++;
        vector<int> tmpV(1); tmpV[0] = i+1; ans.push_back(tmpV);
        DFS(i);
    }
    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++) sort(ans[i].begin(), ans[i].end());
    cout << Count << endl;
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i].size();
        for (int j=0; j<ans[i].size(); j++) cout << " " << ans[i][j];
        cout << endl;
    }
	return 0;
}
