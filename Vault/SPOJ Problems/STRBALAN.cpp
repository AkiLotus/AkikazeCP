#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

string s; int n;
vector<int> Diff;

void Input() {
	cin >> s; n = s.size();
	Diff.resize(n, 0);
}

void Solve() {
	for (int i=0; i<n; i++) {
		if (i == 0) {
			if (s[i] == '(') Diff[0] = 1;
			else Diff[0] = -1;
		}
		else if (s[i] == '(') Diff[i] = Diff[i-1] + 1;
		else if (s[i] == ')') Diff[i] = Diff[i-1] - 1;
	}
	int ans = 0;
	if (Diff[n-1] < 0) {
		int threshold = 0;
		while (threshold < n && Diff[threshold] >= 0) threshold++;
		for (int i=0; i<n; i++) {
			if (s[i] == '(') continue;
			ans += (i <= threshold);
		}
	}
	else if (Diff[n-1] > 0) {
		int threshold = n-1;
		while (threshold >= 0 && Diff[threshold] > +1) threshold--;
		for (int i=0; i<n; i++) {
			if (s[i] == ')') continue;
			ans += (i > threshold);
		}
	}
	cout << ans;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/