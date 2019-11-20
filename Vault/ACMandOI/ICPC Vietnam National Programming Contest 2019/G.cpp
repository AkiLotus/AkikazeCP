/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: G.cpp
// Time created: Sun Nov 03 2019 00:51

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

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int h; vector<int> x;
/************************************************/

/************** [FUNCTIONS] **************/

int slv(vector<int> f,int tmp)
{
	int l=0;
	int r=f.size()-1;
	int mid=0;
	while(l<=r)
	{
		int midd=(l+r)/2;
		if(f[midd]<=tmp)
		{
			l=midd+1;
			mid=midd;
		}
		else r=midd-1;
	}
	return mid;
}
i64 solve(vector<int> pos)
{
	vector<i64> pre(pos.size(),0);
	pre.push_back(0);
	if(pos.size()==1)return 0LL;
	for(int i=0;i<pos.size();i++)pre[i]=pos[i];
	for(int i=1;i<pre.size();i++)pre[i]+=pre[i-1];
	i64 anss=1e18;
	i64 t=pre.back();
	int n=pre.size()-1;
	for(int i=1;i<pos.size();i++)
	{
		int vt=slv(pos,pos[i]/2);
		i64 ans=pre[vt];
		i64 len=i-(vt+1)+1;
		ans+=pos[i]*len-(pre[i]-pre[vt]);
		len=n-(i+1);
		i64 sum=t-pre[i];
		ans+=sum-1LL*pos[i]*len;
		anss=min(anss,ans);
	}
	return anss;
}




void Input() {
	cin >> h; x.resize(h);
	for (auto &z: x) cin >> z;
}

void Solve() {
	
	vector<int> l,r;
	r.push_back(0);l.push_back(0);
	for(auto z:x)if(z<0)l.push_back(abs(z));
	else if(z>0)r.push_back(abs(z));
	sort(l.begin(),l.end());
	i64 suml=0,sumr=0;
	for(auto z:l)suml+=z;
	for(auto z:r)sumr+=z;
	cout<<min(suml+solve(r),sumr+solve(l));
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifndef Akikaze
		if (OImode) {
			assert(freopen(infile, "r", stdin));
			assert(freopen(outfile, "w", stdout));
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/