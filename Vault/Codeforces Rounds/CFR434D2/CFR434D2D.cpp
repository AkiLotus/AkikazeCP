#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long strtoll(string z) {
	long long result = 0, sign = 1, i = 0;
	if (z[0] == '-') {
		i = 1; sign = -1;
	}
	for (; i<z.size(); i++) {
		result *= 10;
		result += (z[i] - '0');
	}
	return result * sign;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	vector<string> Substr[n];
	vector<pair<string, int>> sub;
	vector<string> ans(n);
	for (int i=0; i<n; i++) ans[i] = "1234567890";
	for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=1; j<=9; j++) {
            for (int k=0; k<10-j; k++) {
                string tmp = "";
                for (int l=0; l<j; l++) tmp += a[i][k+l];
                if (find(Substr[i].begin(), Substr[i].end(), tmp) == Substr[i].end()) Substr[i].push_back(tmp);
            }
        }
        for (int j=0; j<Substr[i].size(); j++) {
            pair<string, int> z; z.first = Substr[i][j]; z.second = i;
            sub.push_back(z);
        }
	}
	sort(sub.begin(), sub.end());
	for (int i=0; i<sub.size(); i++) {
        if (i == 0) {
            if (sub[i].first == sub[i+1].first) continue;
        }
        else if (i == sub.size()-1) {
            if (sub[i].first == sub[i-1].first) continue;
        }
        else if (sub[i].first == sub[i-1].first || sub[i].first == sub[i+1].first) continue;
        if (ans[sub[i].second].size() > sub[i].first.size()) ans[sub[i].second] = sub[i].first;
	}
	for (int i=0; i<n; i++) cout << ans[i] << endl;
	return 0;
}
