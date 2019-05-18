/********************************************************
*||  Code written by Akikaze                          ||*
*||  Duy-Bach Le, #Team4T's Chief Executor            ||*
*||  #Team4T Tertiary Flagship - Oblivion             ||*
*||                                                   ||*
*||  Written by a random fan of momocashew and Chiho  ||*
********************************************************/

/***********************************************
** File name: CFR558D2D.cpp
** Time created: Thu May 09 2019 14:33
***********************************************/

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

void ConfigMonitor();
char infile[] = "FILE.IN";
char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
string c, s, t;
int dp[51][51][1000];
vector<vector<int>> nextMatchPrefix_S;
vector<vector<int>> nextMatchPrefix_T;
/************************************************/

/************** [FUNCTIONS] **************/
vector<int> Z_Algo(string S) {
	vector<int> z(S.size()); int x = 0, y = 0;
	for (int i=1; i<S.size(); i++) {
		z[i] = max(0, min(z[i-x], y-i+1));
		while (i+z[i] < S.size() && S[z[i]] == S[i+z[i]]) {
			x = i; y = i + z[i]; z[i]++;
		}
	}
	return z;
}

int calculatePrefix(string sample, string templ) {
	string Token = templ; Token += '#';
	Token += sample;
	vector<int> Z = Z_Algo(Token);
	for (int i=templ.size()+1; i<Z.size(); i++) {
		if (i + Z[i] == Token.size()) return Z[i];
	}
	return 0;
}

void PreprocessST() {
	nextMatchPrefix_S.resize(s.size()+1, vector<int>(26, 0));
	nextMatchPrefix_T.resize(t.size()+1, vector<int>(26, 0));
	for (int i=0; i<=s.size(); i++) {
		string temp = "";
		for (int x=0; x<i; x++) temp += s[x];
		for (int x=0; x<26; x++) {
			temp += char(97 + x);
			nextMatchPrefix_S[i][x] = calculatePrefix(temp, s);
			temp.pop_back();
		}
	}
	for (int i=0; i<=t.size(); i++) {
		string temp = "";
		for (int x=0; x<i; x++) temp += t[x];
		for (int x=0; x<26; x++) {
			temp += char(97 + x);
			nextMatchPrefix_T[i][x] = calculatePrefix(temp, t);
			temp.pop_back();
		}
	}
}

void Input() {
	cin >> c >> s >> t;
}

void Solve() {
	for (int i=0; i<51; i++) {
		for (int j=0; j<51; j++) {
			for (int k=0; k<1000; k++) {
				dp[i][j][k] = INT_MIN;
			}
		}
	}
	PreprocessST();
	if (c[0] == '*') {
		dp[nextMatchPrefix_S[0][s[0]-'a']][nextMatchPrefix_T[0][s[0]-'a']][0]
		= max(dp[nextMatchPrefix_S[0][s[0]-'a']][nextMatchPrefix_T[0][s[0]-'a']][0], 
		(int)(nextMatchPrefix_S[0][s[0]-'a'] == s.size()) - (nextMatchPrefix_T[0][s[0]-'a'] == t.size()));

		dp[nextMatchPrefix_S[0][t[0]-'a']][nextMatchPrefix_T[0][t[0]-'a']][0]
		= max(dp[nextMatchPrefix_S[0][t[0]-'a']][nextMatchPrefix_T[0][t[0]-'a']][0], 
		(int)(nextMatchPrefix_S[0][t[0]-'a'] == s.size()) - (nextMatchPrefix_T[0][t[0]-'a'] == t.size()));

		for (int x=0; x<26; x++) {
			if (x == (s[0] - 'a')) continue;
			if (x == (t[0] - 'a')) continue;
			dp[0][0][0] = max(dp[0][0][0], 0);
			break;
		}
	}
	else {
		dp[nextMatchPrefix_S[0][c[0]-'a']][nextMatchPrefix_T[0][c[0]-'a']][0]
		= max(dp[nextMatchPrefix_S[0][c[0]-'a']][nextMatchPrefix_T[0][c[0]-'a']][0], 
		(int)(nextMatchPrefix_S[0][c[0]-'a'] == s.size()) - (nextMatchPrefix_T[0][c[0]-'a'] == t.size()));
	}
	int ans = INT_MIN;
	for (int k=0; k < c.size(); k++) {
		for (int i=0; i<51; i++) {
			for (int j=0; j<51; j++) {
				if (dp[i][j][k] == INT_MIN) continue;
				if (k == c.size() - 1) {ans = max(ans, dp[i][j][k]); continue;}
				if (c[k+1] == '*') {
					if (i < s.size()) {
						dp[nextMatchPrefix_S[i][s[i]-'a']][nextMatchPrefix_T[j][s[i]-'a']][k+1]
						= max(dp[nextMatchPrefix_S[i][s[i]-'a']][nextMatchPrefix_T[j][s[i]-'a']][k+1], 
						dp[i][j][k] + (nextMatchPrefix_S[i][s[i]-'a'] == s.size()) - (nextMatchPrefix_T[j][s[i]-'a'] == t.size()));
					}

					if (j < t.size()) {
						dp[nextMatchPrefix_S[i][t[j]-'a']][nextMatchPrefix_T[j][t[j]-'a']][k+1]
						= max(dp[nextMatchPrefix_S[i][t[j]-'a']][nextMatchPrefix_T[j][t[j]-'a']][k+1], 
						dp[i][j][k] + (nextMatchPrefix_S[i][t[j]-'a'] == s.size()) - (nextMatchPrefix_T[j][t[j]-'a'] == t.size()));
					}

					if (i == s.size() || j == t.size()) {
						for (int x=0; x<26; x++) {
							dp[nextMatchPrefix_S[i][x]][nextMatchPrefix_T[j][x]][k+1]
							= max(dp[nextMatchPrefix_S[i][x]][nextMatchPrefix_T[j][x]][k+1], 
							dp[i][j][k] + (nextMatchPrefix_S[i][x] == s.size()) - (nextMatchPrefix_T[j][x] == t.size()));
						}
					}

					for (int x=0; x<26; x++) {
						if (i < s.size() && x == (s[i] - 'a')) continue;
						if (j < t.size() && x == (t[j] - 'a')) continue;
						dp[nextMatchPrefix_S[i][x]][nextMatchPrefix_T[j][x]][k+1]
						= max(dp[nextMatchPrefix_S[i][x]][nextMatchPrefix_T[j][x]][k+1], 
						dp[i][j][k] + (nextMatchPrefix_S[i][x] == s.size()) - (nextMatchPrefix_T[j][x] == t.size()));
						break;
					}
				}
				else {
					dp[nextMatchPrefix_S[i][c[k+1]-'a']][nextMatchPrefix_T[j][c[k+1]-'a']][k+1]
					= max(dp[nextMatchPrefix_S[i][c[k+1]-'a']][nextMatchPrefix_T[j][c[k+1]-'a']][k+1], 
					dp[i][j][k] + (nextMatchPrefix_S[i][c[k+1]-'a'] == s.size()) - (nextMatchPrefix_T[j][c[k+1]-'a'] == t.size()));
				}
			}
		}
	}
	cout << ans << endl;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ConfigMonitor();
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) cin >> T;
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/

/************** [MASTER CONTROLS - PHASE 2] **************/
void ConfigMonitor() {
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
}
/*********************************************************/