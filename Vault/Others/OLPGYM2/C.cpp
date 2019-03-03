// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
//typedef tuple<i64, i64> tii;
//typedef tuple<i64, i64, i64> tiii;

// custom typedef here
struct data {
	int r, g, b, id;
	int ur, ug, ub;
	int sumu;
	data() {
		r = 0; g = 0; b = 0; id = 0;
		ur = 0; ug = 0; ub = 0; sumu = 0;
	}
};

// global variables here


// functions here
bool red (data x, data y) {
	return (x.r < y.r);
}

bool green (data x, data y) {
	return (x.g < y.g);
}

bool blue (data x, data y) {
	return (x.b < y.b);
}

bool uniqueness (data x, data y) {
	return (x.sumu < y.sumu || (x.sumu == y.sumu && x.id > y.id));
}

int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code here
	int n; cin >> n;
	vector<data> A(n);
	for (int i=0; i<n; i++) {
		cin >> A[i].r >> A[i].g >> A[i].b >> A[i].id;
	}
	sort(A.begin(), A.end(), red);
	for (int i=0; i<n; i++) {
		if (i == 0 && n > 1 && A[1].r == A[0].r) A[i].ur = 0;
		else if (i == 0) A[i].ur = A[1].r + 360 - A[n-1].r;
		else if (i == n-1 && n > 1 && A[n-2].r == A[n-1].r) A[i].ur = 0;
		else if (i == n-1) A[i].ur = A[0].r + 360 - A[n-2].r;
		else if (A[i-1].r == A[i].r || A[i+1].r == A[i].r) A[i].ur = 0;
		else A[i].ur = A[i+1].r - A[i-1].r;
		A[i].sumu += A[i].ur;
	}
	sort(A.begin(), A.end(), green);
	for (int i=0; i<n; i++) {
		if (i == 0 && n > 1 && A[1].g == A[0].g) A[i].ug = 0;
		else if (i == 0) A[i].ug = A[1].g + 360 - A[n-1].g;
		else if (i == n-1 && n > 1 && A[n-2].g == A[n-1].g) A[i].ug = 0;
		else if (i == n-1) A[i].ug = A[0].g + 360 - A[n-2].g;
		else if (A[i-1].g == A[i].g || A[i+1].g == A[i].g) A[i].ug = 0;
		else A[i].ug = A[i+1].g - A[i-1].g;
		A[i].sumu += A[i].ug;
	}
	sort(A.begin(), A.end(), blue);
	for (int i=0; i<n; i++) {
		if (i == 0 && n > 1 && A[1].b == A[0].b) A[i].ub = 0;
		else if (i == 0) A[i].ub = A[1].b + 360 - A[n-1].b;
		else if (i == n-1 && n > 1 && A[n-2].b == A[n-1].b) A[i].ub = 0;
		else if (i == n-1) A[i].ub = A[0].b + 360 - A[n-2].b;
		else if (A[i-1].b == A[i].b || A[i+1].b == A[i].b) A[i].ub = 0;
		else A[i].ub = A[i+1].b - A[i-1].b;
		A[i].sumu += A[i].ub;
	}
	sort(A.begin(), A.end(), uniqueness);
	for (int i=0; i<n; i++) cout << A[i].id << endl;
	return 0;
}
