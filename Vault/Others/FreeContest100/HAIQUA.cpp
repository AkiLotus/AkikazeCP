/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: HAIQUA.cpp
// Time created: Sat May 11 2019 14:52

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
struct node{
	int sum, cnt1, cnt2;
	node() {sum = 0; cnt1 = 0; cnt2 = 0;}

	node operator+(const node& b) {
		node x;
		x.sum = this->sum + b.sum;
		x.cnt1 = this->cnt1 + b.cnt1;
		x.cnt2 = this->cnt2 + b.cnt2;
		return x;
	}

	node operator+=(const node& b) {
		node x;
		x.sum = this->sum + b.sum;
		x.cnt1 = this->cnt1 + b.cnt1;
		x.cnt2 = this->cnt2 + b.cnt2;
		return x;
	}
};

int k; vector<int> a;
vector<node> Tree;
/************************************************/

/************** [FUNCTIONS] **************/
void ConstructTree(int id, int st, int en) {
	if (st == en) {
		Tree[id].cnt1 += (a[st] == 1);
		Tree[id].cnt2 += (a[st] == 2);
		Tree[id].sum += a[st]; return;
	}
	ConstructTree(id*2+0, st, (st+en)/2+0);
	ConstructTree(id*2+1, (st+en)/2+1, en);
	Tree[id] = Tree[id*2+0] + Tree[id*2+1];
}

int ProcessTree(int id, int st, int en, int requiredValue) {
	if (st == en) {Tree[id] = node(); return st+1;}
	int returnSignal = -1;
	if (Tree[id*2+0].sum < Tree[id*2+1].sum) {
		if (!Tree[id*2+1].cnt1 && !Tree[id*2+1].cnt2) return -1;
		if (!Tree[id*2+1].cnt1 && requiredValue == 1) return -1;
		if (!Tree[id*2+1].cnt2 && requiredValue == 2) return -1;
		if (requiredValue != 2) returnSignal = ProcessTree(id*2+1, (st+en)/2+1, en, 1);
		if (returnSignal == -1 && requiredValue != 1) returnSignal = ProcessTree(id*2+1, (st+en)/2+1, en, 2);
	}
	else if (Tree[id*2+0].sum > Tree[id*2+1].sum) {
		if (!Tree[id*2+0].cnt1 && !Tree[id*2+0].cnt2) return -1;
		if (!Tree[id*2+0].cnt1 && requiredValue == 1) return -1;
		if (!Tree[id*2+0].cnt2 && requiredValue == 2) return -1;
		if (requiredValue != 2) returnSignal = ProcessTree(id*2+0, st, (st+en)/2+0, 1);
		if (returnSignal == -1 && requiredValue != 1) returnSignal = ProcessTree(id*2+0, st, (st+en)/2+0, 2);
	}
	else if (Tree[id*2+0].sum == Tree[id*2+1].sum) {
		if (requiredValue == 2) return -1;
		if (!Tree[id*2+0].cnt1 && !Tree[id*2+1].cnt1) return -1;
		if (Tree[id*2+0].cnt1 > Tree[id*2+1].cnt1) returnSignal = ProcessTree(id*2+0, st, (st+en)/2+0, 1);
		if (Tree[id*2+0].cnt1 < Tree[id*2+1].cnt1) returnSignal = ProcessTree(id*2+1, (st+en)/2+1, en, 1);
		if (Tree[id*2+0].cnt1 == Tree[id*2+1].cnt1 && Tree[id*2+0].cnt2 > Tree[id*2+1].cnt2) {
			returnSignal = ProcessTree(id*2+0, st, (st+en)/2+0, 1);
		}
		else returnSignal = ProcessTree(id*2+1, (st+en)/2+1, en, 1);
	}
	Tree[id] = Tree[id*2+0] + Tree[id*2+1];
	return returnSignal;
}

void Input() {
	cin >> k; a.resize(1 << k);
	Tree.resize(1 << (k + 1));
	for (auto &z: a) cin >> z;
}

void Solve() {
	ConstructTree(1, 0, (1 << k) - 1);
	vector<int> Obtained;
	while (true) {
		int returnSignal = ProcessTree(1, 0, (1 << k) - 1, -1);
		if (returnSignal == -1) break;
		else Obtained.push_back(returnSignal);
	}
	cout << Obtained.size() << endl;
	for (auto &z: Obtained) cout << z << " "; cout << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifdef Akikaze
		cout << "Source code by #Team4T-Akikaze.\n";
		cout << "Input: " << ((OImode) ? infile : "stdin");
		cout << " | Output: " << ((OImode) ? outfile : "stdout") << endl << endl;
		cout << "MultiTest-Mode: " << ((MultiTest) ? "ON\n" : "OFF\n");
		cout << "Interactive-Mode: " << ((Interactive) ? "ON\n\n" : "OFF\n\n");
	#else
		if (OImode) {
			freopen(infile, "r", stdin);
			freopen(outfile, "w", stdout);
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/