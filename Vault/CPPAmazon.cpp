#include <iostream>
#include <algorithm>
using namespace std;

bool optimalSort(string a, string b) {
    for (int i=0; i<max(a.size(), b.size()); i++) {
        if (i == a.size()) return (a[0] >= b[i]);
        if (i == b.size()) return (b[0] <= a[i]);
        if (a[i] != b[i]) return (a[i] > b[i]);
    }
    return true;
}

int main() {
    //freopen("data.in", r, stdin);
    //freopen("ketqua.out", w, stdout);
	int t;
	cin >> t;
	while (t-- > 0) {
        int n;
        cin >> n;
        string num[n];
        for (int i=0; i<n; i++) cin >> num[i];
        sort(num, num+n, optimalSort);
        for (int i=0; i<n; i++) cout << num[i];
        cout << endl;
	}
	return 0;
}
