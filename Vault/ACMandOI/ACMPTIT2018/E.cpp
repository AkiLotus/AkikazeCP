/**
	Template by Akikaze (秋風) - formerly proptit_4t41.
	Code written by a random fan of momocashew and Chiho.
	
	H△G x Mili - November 27th, 2013
	Mag Mell (Mili) - Sep 17th, 2014
	H△G x Mili Vol.2 - May 9th, 2015
	Miracle Milk (Mili) - Oct 12th, 2016
	青色フィルム (H△G) - February 14th, 2018
	Millennium Mother (Mili) - April 25th, 2018
**/

/** -----PRAGMA----- **/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
vi HashMod = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/


/** -----GLOBAL VARIABLES----- **/
i64 T, N;


/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> T;
}

void ProSolve() {
	while (T--) {
		cin >> N; vi a(N);
		for (i64 i=0; i<N; i++) cin >> a[i];
		vector<vi> st(2000009);
		for (i64 i=1; i<(1<<N); i++) {
			i64 sum = 0;
			for (i64 j=0; j<N; j++) {
				if ((i & (1 << j)) != 0) sum += a[j];
			}
			//tracker2(i, sum);
			st[sum].pub(i);
		}
		bool flag = false;
		for (i64 i=1; i<2000009; i++) {
			if (st[i].size() <= 1) continue;
			vi BitCnt(N, 0);
			for (i64 j=0; j<st[i].size(); j++) {
				for (i64 k=0; k<N; k++) {
					if ((j & (1 << k)) != 0) BitCnt[k]++;
				}
			}
			bool f2 = true;
			for (i64 j=0; j<N; j++) {
				if (BitCnt[j] >= N) {
					f2 = false; break;
				}
			}
			if (f2) {flag = true; break;}
		}
		if (flag) cout << "YES\n"; else cout << "NO\n";
	}
}

/** -----MAIN FUNCTION----- **/
int main() {
			#ifdef Akikaze
			//freopen("FILE.INP", "r", stdin);
			//freopen("FILE.OUT", "w", stdout);
			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}

/**
KKKKWWWWK;:.....:;,,,,,,,::,,,,,,,::,,,,,,i;,;ttttttt;:....:;EEDLffjfLGKWWWKLjjjfDWWWWWDffjffffi::::
WWWWWWWWW;:.....:;,,,,,,,::,,,,,,,:::,,,,,;;,,ttttttt,:....:,GDDGLLffLGDWWWKLjttjGWWWWWDfjjjjjji:...
WWWWWKWWW;:.....:,,,,,,,,::,,,,,,,:::,,,,,;;,;ttttttt,:....:,LGGGGGLLLLDWWWKftttjGWWWWWGjjjjjjj;:...
WWWWKKKWW;:.....:,,,,,,,,::,,,,,,,:.:,,,,,;;,,ttttttt,:....:,DDGGGGLLLLDWWWKfttttGWWWWWGjtjjjjj;:...
WWWWWWWWWi:.....:,,,,,,,,::,,,,,,,:::,,,,,;;,,ttttttt,......,EDGGGLLLLLDWWWKjtittGWWWWWLjtttttt;:...
WWWWWWWWWi:.....:,,,,,,,,::,,:,,,,:::,,,,,;;,;ttiiiit,......,DDLLLLLfLLDWWWKjiiitGWWWWWLttttttt;:...
WWWWWWWWWi:.....:::::::::::::::::::.:::::::,,,,,,;;;;,:.....,fLfffffjffGKKWEjiiitLWWWWWLttttttt;:...
WWWWWWKEDi:.....:::.::.:.:.......:..::::::::::::::::::......:,,,,,,,,,,;;;;;,,,,,,;;;;;;,,,;;;;,:...
KKEEKKEDG;:......::,,::,,:::::::::::::::::::.:::::::::......:::::::::::::::::::::::::::::::::::::...
jjttffLDG;:......:,ii;;ii,:,ii;;ii,:,i;,,;;::,;,,,,,:.......::,,,,,,:::,,:,,:::,,:,,,::::,::,::::...
ii;iiitLf;:......:,it;;it;:,it;;tt,:,tt;;ti,:;i;;it;:.......:,ii;;ii,:;ti;it;::;;;;ti,:;i;;ii,::....
iiiiiijft,:......:,ii,,;i,:,ii;;ii,:,ii;;ii,:;i;;;i;:.......:,ii;;ii,:,t;;it;::;;;;ti::;i;;ii,::....
tttttjffi,.......:,;;,,;;,:,;;;,;;,:,;;,,;;::,;,,;;,:........,;;,,i;,:,;;,;i,::;;,;i;::;;;,;i,:.....
ffjjffLft;:......:,i;;,;i,:,ii;;ii,:,ii;,;;::,;;,;;,:........,;;,,;;::,;,,;;,::;;,,i;::;;;,;;,:.....
LLLLLGGGf;:......:,ii;;it;:,tt;;tt,:,ii;;ii::;i;;;i;:........,ii;;i;::,i;;ii;:,ii;;ti::;i;;ii,:.....
DGGGGDDDLi:......::;;,,;;,::ii;;ii,:,i;,;i;::;i;;;i;:........,ii;;ii::;i;;;t;:,ti;;ti::;t;;tt,:.....
EEEEDDEDGt:......::::::::::::::::::::,:::,:::,,,,,,,::.......:,,,,,,:::,,,,;,::;,,,;;::,;,,;;,:.....
EEEEDDEEDj:....................................::::::........:::::::::::::::::::::::::::::::::::....
EEEEDDDEEG;:......................................................::................................
EEKEEEEEEGj:..............................................:.........................................
KKKKKKKKKEL;:............................................::.........................................
WWWWWWWKKKDj:.........................................:::::...::::,:............................::::
WWWWWWWWWKEG,:............::::................:jfLffLLj::,,::::.::,:.......................:::::,,;i
KWWWWWWWWWKD;::::,,,,,,,,,;;;,;::::::::..::.;tffLjffDGjfttL,,:::::,,,:.............:.......:,,,,;;ii
KKWWWWWWWWft,:::,tGGGGGGLGGfji;;tfttttfffLL;ittjjjLLGLGffEjttji,,,::;i,,,,,;;;;;;;,;,,,,;;,,,;;;;;;i
KKKKKKKWWD;:::..:;DGDEEEEEEGji,;;iitjittLttit;tjjfDGGfLfGfGffjfjfit,;;;itLDEDDDGGGGGjiitti;;itji;;;i
KKKEDEEKWK;:....:;GGDKWWKKELLji;;iiti;;;tjjjLtfjjtfjLLLLGffLLLLfLLj;;,,;;tDEDDDDGGGLt;;tii;;iitiitit
WWKEDDEKWWG,:...:;DKDEW#WEjt;;i;ii;;;;;,GLDDGDDLGEitDjLLGGGLDGfEELfGi,,i;;tjLGDGLGEjiiitttiitttiiitj
WWWKKKEEKKWj::.::iDEDDEWWDii;;;;;;,,;;,,LDEGEKEDELGLfGLfLLLfDGKWDELGLjii;;;;tGGLfGEjiiiiiittti;;;;it
WWKKKEDDDKKKt;,;iLGGGLLLGfiii;i;,;i;ii;DDKDLKEEEKKDKfLjEfELDGEKELEKEEtti;;i;tffffLGLt;;ttttjt;;iittj
WWKKEDGGGDEEEDDDGfjtttiii;;,,;i;,ii;;itEKKKKWKKKKKKEEELtLfDGKWDEWKKLLGDj,;iijLfjjjfLfitjtttjtittjfff
KEEDGLffLGGGGGLfjti;;;ii;;,;,;iii;,iiiDWKKKKWWW#WWWKKEEDKGDfWfKWWEGGGjiti;iitjtttttttittiittttjjjttf
EDDGLfjjfLLfffjtti;;;;tjt;;;,;;;;;,,;;KWWKEWWWWWWKEKKEKDEEDWEKWKEDDDEG,,iii;;iiiiii;;;iii;;;iitttttL
KKEEDGjitffLLLffjti;;itjj;;,,;,;,;,,;DKWWWWWWWWWWWKWWEWKKW#EEKKKEGWWEj;:,i;,,;iti;;;iiiiii;;iitiijjD
WWWDLfjiiitfDGfLLffttjjji,,,;;;;;,,,;KWWKWWWWWWWWKWWWWWKWWWWKKKEWWWKfii,:;;;;tti;,,tGGGLGGLLLfjjjfDD
WWDfjtiii;;;;;,;;iitfLj;,,:,i;i;ti;;jWWWWWWW#W#WWWWWWWWWWWWEWWGW#KWGjti,:,,,,iti;,,fWEjtjLLjfLjjjji;
WDGfji;;iii;;,:,,,,,;;;;;,,;;ii;;i;;KWWWWWWW#W#WKWWW#W###WGWE#WWKWKfti;,,:,;;;ff;;;fWKfjt;;ijfjjfi,:
EGGGfjiitiii;,,,,,,,;;;ti;;;iii;;t;iWWWWWWWW#WKKWWWWWW###WW#WWWWKELjti;;;,,,,,;;;;;jGGjt;;itjjtit,:.
LEEGGLjjji;;;;,,,,;;iitttt;;tti;;tfGW#WW#WKWWWK#WW##W###WWWWW#WWKELtii;;;;,,,,;;;,;fji,;iii;iti,;,:.
fWDLGLfLjii;;;,,,;;;;;;;iii;iji;itfEWWWWW#WW#W##WW#W######W#WWWKGLjiii;;;;i;;;;ti;;ti;:,;i;,;;;:,,:.
fWEDGLffjjti;;,:,,,,,,;iii;;tjt;itfKWWWWWW##WW#WW###W##W###W#WELjtii;;;,;;ii;,,i,,ij;,,,;i;;;,,::...
fWWKGtttii;,;i,,;i;,;iit;tf;;tfiitjWWW##W#WW#WW##WWW########WKftitii;;;;t;tt;,,,::;,:,;;ii;;;i;:....
fWKKLtiii;,,;ti;tjtitii;,,;;tjftiiEWWWWWWW##WWW##W##K##W###WWEtii;;;;ffDKjfji;,,:;;;;;;itttiijt,:...
LWKEjttiii;ijjfGLjttti;;;;;iifLt;;EWW#W#WWWKWK#WW###WW#####WKGiiiiitjfffGjjti;;;;t;,;;ttijiiijti;:..
LKKEtittjLjjGDDEEGji;;;;;iittGGf;iKWWWWWWEEWW#WWWW#KKKW###WWKfii;itLGLjiffj;;;,;;ii;,,jjjiijt,,;,,:.
LKKDjijLGLfLDKKftjt,,::,;;;LffLGjKKWWWWWWKWWWW#WWW#WWKWW##WEGjii;;iLDKEtjjt;t;;,,;iittLLDjtLfi,,:::.
LKEELffLGLLDDEj,,;tt;::,ittfGfjDGDWWKWW#KWKW##WW###WWEEKWWKDft;i;;;tGK#Eitiii;,:,;LfjfLtLLtLjjti,:..
GKEKDGLGGGDEEDii;;itti;;jtijLfjtGKWWWWWKWEWW#####W#WWGDEKKEDfi;;;;,,;fGt;i;;i;,,ittjjtttjGGELLti;:..
GEEDGfGGLffLLiiji;;;;tjtfjjffLfjGWWWWWWWWWWW#######GKDDDEEEDtti;;;,,,tt;,i,;jfttij;jfitfjLGEEf;;,:..
GEEDLjLDDjtfi,ijt;iitff;tDDLfGLEGWW#WWWWW#######W##EGEDGDEEGjiii;i;;,,,,,,,;jGt;ttfjjjifDDfLEE;::,::
LEEDLjffjfGGiifGDjfttLDitffjfGjDDKWWWWKWW##W#W#####KGLGGDGDLttiiiiii;,,;;:;tit,,tiii;iiLGGGtLEi:.:,:
GEEELjfttfGLfjfGDLGGGKKfLfLGLLjGKKWWWWWW###########DtfGGLEGfjttttttti;,;;:ii;,,;;i,i;iiLLj;;fft:.::.
GEEGGLLLfjjfGELLLfGGGLEt;;tjGGLEW##WWWWW##W########WWEGLLLftttttttjti;,t;,.jt;iiiiijfitjjt;,;tt;,:,,
DDLGGDEDLjjjGEftjLEfffi,,,;tjjEWWWWWWW##WW#########WWWELLjjttittttttti;i;ttjf;ititffjitjfj;::;itiitj
DGLGEEKDjtjLGjttjfLLGj,,;i;iiiDWWWKKWW##W##########WWWELfjttiittttjtttGjjKji,,fGjjfLj;tLft;::,,ittjL
GDGDEKKLttfKDjtLDfLDDi,itttjiiEKWWWWW##############WWKELfjtttitttttjjttEftit;;DDLjfLjijjtti,::,;jjLG
GEDDEKEGjGWWKEKWWEEEEfjfLjttjLKKWKWWW##############WKKEGfjtttttttjjjjt;jfj;tjLEELjfffttiti;;::,,;fDE
GEDDEKKGjLKWW#WWKDGEEEDGDLjtjDKWWKWW###############WKKEDLjjttttjjjjffjt;LjtjfGDGGfLtLjffLjit;:,,,jEE
LEDDEEKGjjLKW###EttDEEGfjLDLEEKWWW##W###W##########WEEEGLfjjjjjtjjfffDDLjjftLLLftfjiLDEDffftj;i;,iDK
LEDEEEEDjtfEW#WWLtjEEGfjjfEKEEWWWWW################WWEEGGLjjjjjjjffLKDEGttjjfjttijfDGLLfjft,;ttt;;fD
LEDEKEEDffGWW#WWDfGELLffLfKEEWWWWW#################KDEDDLLfjjjjjjffLfLLftttjtjfGjifEELfjjj,.:,;ittjj
GEEKKWKEGDKWWW#WWEEELGfjLEEEEWWWW#################WKDDDDGLLfjjjjfLLfjLLjjjjfjjLEDjEWELfjjj;::,,ijfjj
DEEKWWWKEEWWWWWWWWWWEGjfGEEKKWWWW#################WELGEDGGLffjjffLLffjjtjLDLLLfEEjKWELGjfjti;itffffj
EEEKWW#WKKWWWWWWWWW#KLLEDDEKWWWWW##############W#WEELGDDGGLffjfffLfffttttfDGGGLEKDWWKEDitfLLLGGGGLLL
DDEKWW#WKKWWWWWWWWWWEGEKEEKEKWWW#################WGGLGGDGGLfjfffffffji;tjfLGDEEEWKDEGLGijGEEEDGLLLff
GDEKWW#WWKKKKKKKWWWWDEKKEEDLWWW########W########WEDLLLGDGGLGEGtjfffLfi;;;tGDDKEDKLtfDLftttfGfjiii;;;
GDKKWW#WWKKKWKDEKKWWKKKKKKDEWWW##W##############KELLLLGDGGGELjLEjjjfj:,tijDDDEEDEGjjDGjt;,iti;,,,,,,
EKKKWWWWWKKWWKDDKKWWWKKKWKKKWWW##WW###WW###WWW#WEGLffLLGGLEDLLDEL;tGi:,jjGGGDEDLLDGffGji;,;;;,,:,:::
WKKKWWWWWWWWWKDLGEKKWKEKWKKKWW##WWW##WWW##WWW#WEDLfffLLLLEDDEEKKGjfDLjLjiLLLDEDjfGGffGti;;;;;,,,,,,:
WKEEEEEKWWWKEEEGLDEKKEDGEKKWW###WW###WW##WWWWWDGLffffLLLDELDEEKWKEGGGLLLiijttDDLGDDGGLjttiiiiiiii;;;
WKEEt;;LWWWEDDDDDDEEGGGjLEKWW##W####WW#WWKWWWDfjjjjffLLLEEGDKEWWWEDDGGfLfit;,;GGKKEGGfGGGLfjffLLLfjj
WWKi:.:iKKKEEDEEDDDDGGfitKWWW##K###WWW#KEKWWfiiittjjfLLfGEDKKEKWKEDDDGtifftji;jDKKEDGfEKEEEEEEEEKEDD
WKt:  :jEEEEEEEEDDEDDDjtGKKWW##W###WW#GfKWL;,,,;ittjfLfEEDDEKEEKWWELGDLjffjGEfLDWWEDLLEEEEEEKKEEEKKE
Kt:. :iGDDDDDDDDDDDDGGLLKWEW##WW#WW##GDKDi....:,;ittjfKWWKKKKEEKWKKEEGGfjjLDEEGGWKDDfLDGLDKKEEGGDEEE
t:. .;LGGDGGGGGGGGGGLLGGGWWW#WW#WWWWGEj;.      .,;iitftGLKWKKKKDEKEDKKDGftLDDGLGEDLfjDEDDEWWWKDDEKKK
:. .,tLGDDGLLLLLLGGGLLGGDWW##W###WWKK:,        ...;;it;tGEKKWKKEEKEEKKDDt;tGEGfLDDLjfEWWWWW#W#WWWWWW
. .:j;iLGGLffLLLLLLGLLDGDKW######WWW.:           ...;i;;jEKKKKWWKKWWKGLDGtffGGfjGDfjGEKWWWWWWWWWWWWW
..:tGiifLLLffffLLLLLfLGLGKW#####WWW.:             ....;;;DKKKKKWKKKWKLfDKDLjfGjjGGtjLGEWKKKKKKKEDEEK
:,ifLjjLLffffffLLLLLfLLLGKW#W###WW:,               ...::tGKKKEKWKKKKKDfGEEGfLLjfGftjGDEEDEEEDEDDGDED
iitLLtjfffffffffLLLLLLGGDWWWW##WWG..               .....::KDGEKWKKWKKELLEKEjtjjffttLGGEEDDDDDDDDDDDD
Dj;tjtjffffLffjjfLLLLGGGG#######W::                 ....::EEEKKWEDEKKKDLDEDfttffLtfLLLGGGGGGGGGGGGGG
DL,;ttffjjfLffjjLLLLLGDGDW######E:                   ....:.WWKKKEDEKKKKGGDLLjtjfDLfjffLLLLLLLffffffL
DDjitjffjfjjffffLfLLLLDGGWW#####: ..                  ..:..EWKKEKKKWKKKEEDftttjfGfttjjffffffjfjfjjjj
DDjttjjfffjjfffffjfLLLDDDW#####W: ...   . .i,iit;;ft   .....KKKEKKWKWEEKKDfjLLfjfjtjjjjjjjjjjjjjjjjt
DGjtjjffffLfLfffffLLLLGDEW#####t....   .. GG.ttjLDf:,f .....;KKWWWWWWKDEDDLLDGftjjjjjjjjtttttttttttt
DLjjjfffffffffffLLGLLLGDE######: .: .  .. ,.       .jE,:.....EKWWWWWWWKELGDDEGjjjjttttttttttttititti
DfjjfLLfffffLLLLLGDGGEEEKWW###L .:... ...        .    .j......KKWWWWWKKKGDDDEGjtjtttttttiiiiiiiiiiii
DjjfLLfLLfjfGLGGGDDDDDEE#W#W##,.::....... .:...::::..   ;.....iKWWWWWKKEDDGLffttjtttiiii;;;;;;;;;;;,
LjffLLLGLfffGGDDDEDDEEKKWW###W..,.........    :,:::...:: :.....KWWKKKKKEfGDGfffjjtttii;;;;;;;,,,,,,,
LLLLGGGDDGGDEEEEEEDDKKKWWW###,.:,.....  .:  :,,:..:...:,, :.... KWKKWKWGjLDDGLLLttti;;;;,,;;;,,,,,,,
LGLLGGLGDDDEEEEKKKKKKKKW#####:.::........:..,,:::::...:,,:......tKKWWKKDfDKGjjfLttti;;;;,;;;;,,,,,,,
GGfLLLLGDEEEEEEKKKKKKKKWW####..::........::;;,::::::...:,,,......KWWWWEDLDEGjijftiiiii;i;;;i;;;;;;;;
LGffffGEKKKKWKKWWWKWKKKW####j.::::.......:;,,::::,:....:,,:;:.....WWWKKEGEEKGtfjiiiiiiiiiiiiiiiii;;;
LLfLfLEWWWWWWWW#WWWKKEWWW###:.::::::...:::,:,::,:::.....:,,;:.....EWWKKKDEKWKLLtiiiiiiiiiiii;ii;;;;;
LffGGDKWWWWWWWWWKKEEEEWWWW##..::.:::.:.:::,,:,,:::::....:,,:,:.....WWWEEEEKWWKDt;;iiii;;;;;,,;;,,,,,
LffDDDDEEDDEDDEDDEDDDDEKWWWW..::::::::.:..:,:,:,:::.....:,,,;,.....tWKEEEEKWWWDt;;iiii;;,,,:,,,:::::
LLfGGLLGGLGGDDDDDGGDGEEWWE#W.::::::::::::.,,:,,,:::......:,,;,:.....EEEKEDEWWWDi;;;iii;;,,,:,;;,::::
LfjGLLLGGLLGDDGDDLGDGEEWEEWW..:::::,,..:..,,,,,,::.......:,,:,,.....jEEKGGEWWWGt;;iiiii;;,,:,,,,::::
ffjLGGGGGLGDGLLDGLGDEEKWGE#W...::,:,:.::.::,,,,,::.....::::,,,,,.....KKEDDKWKKDj;;iiiiii;,,,,,,,::::
ffjfLLGGLLGDGLLDGLLGEKWWWKWW...::,,,:.:.::,,,:,:,:......::,:,;;,... .EEDDEDKKWEj;;iiiiiii;,,,,,,::::
LftjLLGLLGGDGLGGKGfjDWWWEEW#....:,,,::::::,,,,::::..  ..:::,,,,,:....DEDEEGGDEDfi;;iiiiii;,,:,,:::::
LfjjLGDGLGGGGGGGGEEEEWDGE#W#....::,:::.:::,,,::::.. .....:::,:,,,... GKDEEEDEKEELiiiiiiii;,:,,,:::::
GLjjLDDGGLGGLLLGLLKKEGKWWWW#i...::,:.:::::,,,::....:.::...:.,:,,,:....KDLLDEDEDDLjttttttti,,,;;,::::
GGffDDGGGGDLLLGLfLGKWWW##WW#i;...:,:::,,::,,:::,,,;,;t;: ,i::::,,,:...EDjtGDGLjffjfjjjjttt;;;i;,,:,:
DGffGDLLLGDLLLGfffLGGLW#####,t:.::,:::,,::::;:,;ii;;iitt:::i::;:,,:...LEfjGLLftjLfffjjjttttiti;,,,,:
KEGLGGLffGGLfffjjjfGfffL####;i,:::::::,:::tiiii;i,,;iiii:,;:;,f:,,,:...WKKKKKKDDEEGEfjtttttttt;,,,,,
KEEEDGffLGLjtfffffLGjtjW####;;,.:::..:::jt;;;ii;;i;;iii;:,;;,,,;:::::..WWWWWWKKEEEDEftiiiiitti;,,,,,
DDDDDGLLGGLfjLGfffLGtitjjGW#f;,::::.::,ii;i;;;i;;iiii;;,:,:,;;;W:,:::::WWWWWWWWKGEKEt;;;;;;;;;;,,,,,
GDDDEDDGGLLfLGLjtjLLtittjjjW#;;::.:.:;i;;;,;;;i;;iii;;i.,,,::,:Gj::::::WWWWWWWWWDGGDi;;;;,,,,,,,,,,,
DDEEDGGGDGGGGDLLffLftttjjttjfi;::.::;t,i;,,;,;;;;;;;;;;.,,,,;;:ED:,:,,:KKWWWWWWWWEEKt;;;;,;,,,,,,,,,
DGDEDGLGEDGGGLffffjitttjjiitji;,::::j;,i,;;;;;;;;;;;;;,.:,,:,;,.L#:,,,,WWWWWKWWWWWKEt;;;;;;;,,,,,,,,
LGDEEGLGDGLLLLjjjftitttjftitjLit,,:;j,;i,,,;;,;;,,;;;,::,;,::;,.EG,,:;,WWWWWKWWKKWEEt;;;;;;;;;;;;;,,
GGEEDGGGLfffGLfjtjffjjttjtttjfiii,,tj:ii,:,;;;;;,,,,,,.:,;;,.,,,.GW:,;,WWKWWWWWWWWKGjttttiiitttiiii;
GLLDDDDLffjfGLffjjLfjtitfjjjjLtij;,tf,t;::,,,,,,,,,,,,.,,,,,:,,::;f;;i,KWKKWWWWWWKKLijjjjjjjtttttttt
GLfGGGDLffjfLfjjjfGjtiitfjtjjLLitt:tf;i;,,,;,,,,,,,,,::,,,,,:;;:;.KG:i;WKKWWKWWWWWWGtjjjjjjttttttttt
EEGLLGDGfLfLLffjjLLtiiitfjjjjLfjij,jj;ti,,,,,,,,,,,,,.:,,,,::;;:;::L:iiWWWKWWWWWWWWKLjjjtttttttttiii
DDLffLGGLLfLLjjjjfftiiitftttjGfftttjj;i;:,,,,,,,:::,,.:,,,,,:,,:i,,E;iLWWKKWKKWWWWWKDtttttttttiiiiii
DLfjfLDLffffjttjjfftiiiijtjjfLLLjttfj;it:,,,,:,,,::,,.::,,,,:,,,ii,WtiKWWKKWKKWWWWWEGtiiiiiiiiiiiiii
DfjjjGGfjfLLjjjjfLLjjjjffffffLfjfjtffiti,,,,,,,:,:::::,:,,,,:,,:ii,LtiKWWWKKWWWWWKKKGtiiiiiiiiiiii;i
DGLLLDGfffLGLfffLLfjtttjfjjjffLjfjjtLtti:::,:,:,::::.:,,,,,,,:,:ii;f;;KKWWKKWKWWWWKKEjii;i;;;;;;;;;;
GLLLGGfjfjfLfjjjLGLftttjfjjtjfffLLjjjGtt:,,,,,,,,::: ::,,,,,::,,it;Ei;KWWWKKWKWWWWWWELi;;;;;;;;;;;;;
GGGLGLfjjjfffjjjLDGLjtttjjjjjffjfLffjLti,,,,:,,,,:::.::,,,,:,:,;tt;LiiKKKWWWWWWWWWWWKDi;;;;;;;;;;,,,
GGLLDLffjfffffffGGDGfjtjfjjjjLLLffLjfjtt,,,,,:,:,:::.:::::,:::,itt;ti;KKKWWWWWWWWWKKKEi;;;,,,,,,,,,,
LLLGGjjjffLffjjfLGGLfjjjfjjttjjffjjLfjjt,,,,,,,,,::::::::::,,:,ittDtijWKKWWWWWWWWWWKEDi;;;;;,,,,,,,,
fjLDjijfLLGLfjfLGLfjjjjjfjjjjfLGGLLDjftt;,,,,,:,,,,.:::,,,,,,:,ttt#tiWWWKWWWWWWWWWWWKEj;;;i;;;,,,,,,
jjLEfjjfjfLfjttLGLjtjtttjjtjfLLLGGGDEjftt,,,,:::::: ::::::::::,ttKKjiWWWKKWWWWWWWKWWKKDi;ii;;;;;,,,,
jjfGfffjtjjjjffLGGjtjjiifjjjfLLLGGGGELjLt,,,,,,::::.::::::,:,,,ttWELKEWWWKKKWWWWWWWWWWKj;ii;;;,,,,;;
jjjffffjjffjjffLLLftttitjjjtjfffLLGLGLjft,,,,,:::,,.::::::,,,:;tjWKE,WKWWWKKKWWWWWWWWWWjii;;;,,,,,,;
**/

// Tribute to a friend I owe countless. Thanks, TN.