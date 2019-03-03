#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int n; vector<string> A;
vector<string> Mat;
map<char, string> HextoBin;
int PS2D[5201][5201];

void Input() {
	HextoBin['0'] = "0000";
	HextoBin['1'] = "0001";
	HextoBin['2'] = "0010";
	HextoBin['3'] = "0011";
	HextoBin['4'] = "0100";
	HextoBin['5'] = "0101";
	HextoBin['6'] = "0110";
	HextoBin['7'] = "0111";
	HextoBin['8'] = "1000";
	HextoBin['9'] = "1001";
	HextoBin['A'] = "1010";
	HextoBin['B'] = "1011";
	HextoBin['C'] = "1100";
	HextoBin['D'] = "1101";
	HextoBin['E'] = "1110";
	HextoBin['F'] = "1111";
	cin >> n; A.resize(n);
	Mat.resize(n, "");
	for (auto &s: A) cin >> s;
}

int SumSqr(int x1, int y1, int x2, int y2) {
	int res = PS2D[x2][y2];
	if (x1 > 0) res -= PS2D[x1-1][y2];
	if (y1 > 0) res -= PS2D[x2][y1-1];
	if (x1 > 0 && y1 > 0) res += PS2D[x1-1][y1-1];
	return res;
}

bool valid(int x) {
	for (int x1=0; x1<n; x1+=x) {
		for (int y1=0; y1<n; y1+=x) {
			int x2 = x1+x-1, y2 = y1+x-1;
			int sum = SumSqr(x1, y1, x2, y2);
			if (sum != 0 && sum != x * x) return false;
		}
	}
	return true;
}

void Solve() {
	for (int i=0; i<n; i++) {
		for (auto c: A[i]) {
			Mat[i] += HextoBin[c];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			PS2D[i][j] = (Mat[i][j] == '1');
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == 0 && j == 0) continue;
			if (i > 0 && j > 0) {PS2D[i][j] += (PS2D[i-1][j] + PS2D[i][j-1] - PS2D[i-1][j-1]); continue;}
			if (i > 0) {PS2D[i][j] += PS2D[i-1][j]; continue;}
			if (j > 0) {PS2D[i][j] += PS2D[i][j-1]; continue;}
		}
	}
	for (int x=n; x>1; x--) {
		if (n % x != 0) continue;
		if (valid(x)) {cout << x << endl; return;}
	}
	cout << "1\n";
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
*  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
*  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
