#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam

#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int MultiTest = 1;

int n;

string ans[] = {
"1",
"2",
"5",
"14",
"42",
"132",
"429",
"1430",
"4862",
"16796",
"58786",
"208012",
"742900",
"2674440",
"9694845",
"35357670",
"129644790",
"477638700",
"1767263190",
"6564120420",
"24466267020",
"91482563640",
"343059613650",
"1289904147324",
"4861946401452",
"18367353072152",
"69533550916004",
"263747951750360",
"1002242216651368",
"3814986502092304",
"14544636039226909",
"55534064877048198",
"212336130412243110",
"812944042149730764",
"3116285494907301262",
"11959798385860453492",
"45950804324621742364",
"176733862787006701400",
"680425371729975800390",
"2622127042276492108820",
"10113918591637898134020",
"39044429911904443959240",
"150853479205085351660700",
"583300119592996693088040",
"2257117854077248073253720",
"8740328711533173390046320",
"33868773757191046886429490",
"131327898242169365477991900",
"509552245179617138054608572",
"1978261657756160653623774456"
};

void Input() {
	cin >> n;
}

void Solve() {
	if (n % 2 != 0) cout << "0\n";
	else cout << ans[n/2-1] << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	return 0;
}