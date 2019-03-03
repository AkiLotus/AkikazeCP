#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int ang;

void Input() {
	cin >> ang;
}

void Solve() {
	int centerAngle = ang * 2;
	int numer = centerAngle, denom = 360;
	int g = __gcd(numer, denom);
	numer /= g; denom /= g;
	if (numer == denom - 1) {numer *= 2; denom *= 2;}
	cout << denom << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
