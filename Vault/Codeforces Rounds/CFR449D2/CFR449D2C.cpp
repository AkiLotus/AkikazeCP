/**
	Template by proptit_4t41
	Applied for C++11/C++14
	Add -std=c++14 to your IDE.
**/

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
const long double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----
	f0 is 75 chars long.
	fi (i > 0) (without recursive parts) is 68 chars long.
	Mind that there ARE quotation marks in fi (i > 0).
    -------------------------- **/

/** -----CUSTOM TYPEDEFS----- **/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string firstFragment = "What are you doing while sending \"";
string secondFragment = "\"? Are you busy? Will you send \"";
string thirdFragment = "\"?";
vector<i64> strLen(111111, 75);
vector<i64> secStart(111111, 0);
vector<i64> thiStart(111111, 0);
i64 q, n, k, fir, sec, thi;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	fir = firstFragment.size(), sec = secondFragment.size(), thi = thirdFragment.size();
	for (i64 i=1; i<111111; i++) {
		if (strLen[i-1] > 1000000000000000000) strLen[i] = 4000000000000000000;
		else strLen[i] = fir + sec + thi + 2 * strLen[i-1];
		secStart[i] = fir + strLen[i-1];
		thiStart[i] = fir + sec + strLen[i-1] * 2;
		//cout << "strLen[" << i << "] = " << strLen[i] << endl;
	}
	cin >> q;
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	while (q--) {
		cin >> n >> k;
		if (k > strLen[n]) cout << '.';
		else {
			if (n == 0) cout << f0[k-1];
			else {
				k = k - 1;
				bool requiredLoop = true;
				while (n > 0) {
					if (k >= 0 && k < fir) {cout << firstFragment[k]; requiredLoop = false; break;}
					if (k >= secStart[n] && k < secStart[n]+sec) {cout << secondFragment[k-secStart[n]]; requiredLoop = false; break;}
					if (k >= thiStart[n] && k < thiStart[n]+thi) {cout << thirdFragment[k-thiStart[n]]; requiredLoop = false; break;}
					if (k >= fir && k < secStart[n]) {
						k -= fir; n--;
					}
					else {
						k -= (secStart[n] + sec); n--;
					}
				}
				if (requiredLoop) cout << f0[k];
			}
		}
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// code written by a random fan of momocashew
	// world.execute(me);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}
