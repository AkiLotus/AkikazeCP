#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int n, k; vector<int> d;
int offset = 10;

void Input() {
	cin >> n >> k; d.resize(k);
	for (auto &z: d) cin >> z;
}

void Solve() {
	vector<long long> Old(20, 0LL);
	vector<long long> New(20, 0LL);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
