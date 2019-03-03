#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n; string s; vector<int> a;

void Input() {
	cin >> n >> s; a.resize(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	vector<long long> dpH(n), dpA(n), dpR(n), dpD(n);
	for (int i=0; i<n; i++) {
		long long LastH = 0, LastA = 0, LastR = 0, LastD = 0;
		if (i > 0) {LastH = dpH[i-1]; LastA = dpA[i-1]; LastR = dpR[i-1]; LastD = dpD[i-1];}
		dpH[i] = LastH + (s[i] == 'h') * a[i];
		dpA[i] = min(dpH[i], LastA + (s[i] == 'a') * a[i]);
		dpR[i] = min(dpA[i], LastR + (s[i] == 'r') * a[i]);
		dpD[i] = min(dpR[i], LastD + (s[i] == 'd') * a[i]);
	}
	cout << min({dpH[n-1], dpA[n-1], dpR[n-1], dpD[n-1]}) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
