#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 holdtheflower
#define y1 enjoythecolorandscent
#define yn walkthroughthesoulgarden
#define j1 feelthewarmbreathofkindnessandsalvation

#define endl '\n'
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

string Time1, Time2;

int timetomin(string st) {
	int H = ((st[0] - '0') * 10 + (st[1] - '0'));
	int M = ((st[3] - '0') * 10 + (st[4] - '0'));
	return (H * 60 + M);
}

string mintotime(int t) {
	int H = t / 60, M = t % 60;
	string res = "";
	if (H < 10) res += "0";
	res += to_string(H); res += ":";
	if (M < 10) res += "0";
	res += to_string(M); return res;
}

void Input() {
	cin >> Time1 >> Time2;
}

void Solve() {
	int t1 = timetomin(Time1);
	int t2 = timetomin(Time2);
	cout << mintotime((t1 + t2) / 2) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/