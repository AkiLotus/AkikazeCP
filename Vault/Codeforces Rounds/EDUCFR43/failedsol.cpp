#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <ll> Mvt;
typedef stack <ll> Mst;
typedef queue <ll> Mque;
const ll MAX = 1e7+7;
const ll Base = 1e9+7;
const ll cMax = 1e4+7;
#define For(i,a,b) for (ll i=a;i<=b;i++)
#define foR(i,a,b) for (ll i=a;i>=b;i--)
#define Cong_Hoa_Xa_Hoi_Chu_Nghia_Viet_Nam main
#define Doc_Lap_Tu_Do_Hanh_Phuc {ios::sync_with_stdio(false); cin.tie(0);}

struct data{
	ll dau,cuoi,chiso;
};

/* _____Report here_____ */
ll n;
data a[MAX];
data tmp;
/*~~~~~~~~~~~~~~~~~~~~~~~*/
bool cmp(data a, data b){
	if (a.dau > b.dau ) return false;
	if (a.dau==b.dau&&a.cuoi < b.cuoi) return false;
	return true;
}
void init(){
	cin >> n;
	For(i,1,n){
	    if (i == 1) {tmp.dau = 1; tmp.cuoi = 2;}
	    else if (i == n) {tmp.dau = 1; tmp.cuoi = 3;}
	    else {tmp.dau = 2; tmp.cuoi = 4;}
		tmp.chiso = i;
		a[i] = tmp;
	}
	sort(a+1,a+n+1,cmp);
//	For(i,1,n) cout << a[i].dau << " "<<a[i].cuoi<<" "<<a[i].chiso<<"\n";
}
bool check(data a, data b){
	if (a.dau <= b.dau && a.cuoi >= b.cuoi) return true;
	return false;
}
int Cong_Hoa_Xa_Hoi_Chu_Nghia_Viet_Nam () {
/*******/Doc_Lap_Tu_Do_Hanh_Phuc/*******/
	init();
	ll m = n-1;
	For(i,1,m){
		if (check(a[i],a[i+1])){
			cout << a[i+1].chiso << " " << a[i].chiso;
			return 0;
		}
	}
	cout <<"-1 -1";
	return 0;
}

/* Good Lucky*/
/* Code by Hoanghiepd17 */
