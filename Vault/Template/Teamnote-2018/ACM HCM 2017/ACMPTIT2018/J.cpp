#include <bits/stdc++.h>
using namespace std;

string calc(string s) {
	vector<string> can;
	int n = s.length();
		vector<int> last(128, 0);
		for (int i = n - 1; i >= 1; i--) {
			string t = s;
			last[t[i]] = i;
			for (int j = t[i - 1] - 1; j >= '0' + (i == 1); j--) {
				if (last[j]) {
					swap(t[i - 1], t[last[j]]);
					can.push_back(t);
				}
			}
		}
	sort(can.begin(), can.end());
	if (can.empty())
		return "-1";
	return can.back();
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		cout << calc(s) << endl;
	}
}