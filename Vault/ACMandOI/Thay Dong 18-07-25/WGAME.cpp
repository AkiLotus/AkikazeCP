/**********************************************************
 *     Code written by Akikaze                            *
 *     Duy-Bach Le, #Team4T's Chief Executor              *
 *     #Team4T Tertiary Flagship - Oblivion               *
 *                                                        *
 *     Written by a random fan of momocashew and Chiho    *
 **********************************************************/

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
//vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));
/*************************************************/

/************** [BITWISE FUNCTIONS] **************/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }
/*************************************************/

/************** [GLOBAL VARIABLES] **************/
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978
//#undef OImode // Switch this off if submitting OI problems.

i64 m, n, D, len; vector<vector<char>> a; string s;
/************************************************/

/************** [FUNCTIONS] **************/
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();

string requiredFrom(string z) {
	string t = z.substr(0, m+n-2 - (m+n-2)/2);
	reverse(t.begin(), t.end()); return t;
}

bool valid(string z, string t) {
	string u = z; u += t; string v = u;
	reverse(v.begin(), v.end());
	if (u != v) return false;
	if (u.find(s) >= 0 && u.find(s) <= (i64)u.size() - (i64)s.size()) return true;
	return false;
}

void Input() {
	cin >> m >> n >> D >> s;
	len = s.size(); a.rsz(m, vector<char>(n, '#'));
	for (i64 i=0; i<m; i++) {
		for (i64 j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
}

void Solve() {
	//if (a[0][0] == '#' || a[m-1][n-1] == '#') {cout << "0"; return;}
	vector<vector<unordered_map<string, i64>>> dp1(m, vector<unordered_map<string, i64>>(n));
	vector<vector<unordered_map<string, i64>>> dp2(m, vector<unordered_map<string, i64>>(n));
	string x1 = "", x2 = ""; x1 += a[0][0]; x2 += a[m-1][n-1];
	dp1[0][0][x1] = 1; dp2[m-1][n-1][x2] = 1;
	for (i64 x=0; x<(m+n-2)/2; x++) {
		for (i64 i=0; i<m; i++) {
			i64 j = x - i;
			if (i < 0 || i >= m || j < 0 || j >= n) continue;
			for (auto it=dp1[i][j].begin(); it!=dp1[i][j].end(); it++) {
				string z = it->first;
				if (i+1 < m && a[i+1][j] != '#') {dp1[i+1][j][z+a[i+1][j]] += dp1[i][j][z]; dp1[i+1][j][z+a[i+1][j]] %= D;}
				if (j+1 < n && a[i][j+1] != '#') {dp1[i][j+1][z+a[i][j+1]] += dp1[i][j][z]; dp1[i][j+1][z+a[i][j+1]] %= D;}
			}
		}
	}
	for (i64 x=m+n-2; x>(m+n-2)/2; x--) {
		for (i64 i=m-1; i>=0; i--) {
			i64 j = x - i;
			if (i < 0 || i >= m || j < 0 || j >= n) continue;
			for (auto it=dp2[i][j].begin(); it!=dp2[i][j].end(); it++) {
				string z = it->first;
				if (i-1 >= 0 && a[i-1][j] != '#') {
					string t = ""; t += a[i-1][j];
					dp2[i-1][j][t+z] += dp2[i][j][z]; dp2[i-1][j][t+z] %= D;
				}
				if (j-1 >= 0 && a[i][j-1] != '#') {
					string t = ""; t += a[i][j-1];
					dp2[i][j-1][t+z] += dp2[i][j][z]; dp2[i][j-1][t+z] %= D;
				}
			}
		}
	}
	/*
	for (i64 i=0; i<m; i++) {
		for (i64 j=0; j<n; j++) {
			cout << dp1[i][j] << endl;
		}
	}
	cout << "\n--------\n";
	for (i64 i=0; i<m; i++) {
		for (i64 j=0; j<n; j++) {
			cout << dp2[i][j] << endl;
		}
	}
	*/
	i64 ans = 0;
	for (i64 i=0; i<m; i++) {
		i64 j = (m+n-2)/2 - i;
		if (i < 0 || i >= m || j < 0 || j >= n) continue;
		//tracker2(i, j);
		for (auto it=dp1[i][j].begin(); it!=dp1[i][j].end(); it++) {
			string z = it->first, t = requiredFrom(z);
			//tracker2(z, t);
			if (!valid(z, t)) continue;
			if (i+1 < m) {ans += (dp1[i][j][z] * dp2[i+1][j][t]); ans %= D;}
			if (j+1 < n) {ans += (dp1[i][j][z] * dp2[i][j+1][t]); ans %= D;}
			//cout << "ans = " << ans << endl;
		}
	}
	cout << ans;
}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	Input(); TimerStart();
	Solve(); TimerStop();
	return 0;
}
/************************************/

/************** [SUPPORTING FUNCTIONS] **************/
void ControlIO(int argc, char* argv[]) {
	#ifdef Akikaze
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen("WGAME.INP", "r", stdin);
	freopen("WGAME.OUT", "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Akikaze
	TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Akikaze
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}
/****************************************************/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                          Li f                                                                                                  //
//                             # W ;                                                                                              //
//                     .  #.  #   G                                                                                               //
//                W  .##  :  .  #                                                                                                 //
//     j#        #K#  #;   j E                                                                                                    //
//    #, #   # .  ,  L     E                          #             ;Li                                                           //
//  G  # #f   # ;W  .                              G.           ;KKKKKEE                                                          //
//  W  #W#  #   W     L                          i         fEWKKWWWWWWWKWLWKKW                                                    //
//   #                                        E         tfWWWKKKKKWWWWWWW##WWKf                                                   //
//      ##         .  ,  #                  #         jfLWWWWWKKKWWWWWWWWWW#####j                                                 //
//      #        #   #                    #          fLLWWWWWWWKKWWWWWWWWWWWWWWW##                                                //
//    #         L   W   #               #          ifLLWWWWWWWWWWWWWWWWWWWWWWWWWW##i                                              //
//       .    Gt   f #ff              ;           ijfLWWWWWWWWWWWWWWWWWWWWKKWWWWWW###                                             //
//   :      ##       t t   #  :     #            ijfGWWWWWWWKKWWWWWWWWWWKKKKWWWWWW####                                            //
//  D   :   W   K    :    . #     #             jffGWWWWWWKKKKWWWWWWWWWWKKKKWWWWWW####K                                           //
// t          G      E#       # j              tLK#WWWWWWKKKKKWWWWWWWWWWWKKKKWWWWWW####D.                                         //
//D      .  ### E   #j       ; .              DEK##WWWWWKKKKKKWWWWWWWWWWWKWKKWWWWWW#WW#EL                                         //
//    : L  . # :.  ,        i#              .DEK#W#WWKWWKKKKKKWWWWWWWWWWWWWKKWWWWWW#WW##Lt                                        //
//     #    ## K            E               DEK#WWWWKKWWWKKKKKWWWWWWWWWWWWWWKWWWWWWWWWW#Lj:                                       //
//    #     ###      #    W                GEEWW##WWWKK#WWKKKKWWW#WWWWWWWWWWWWWWWWWWWWW#Wft                #                      //
//   # K    ##     .#                     fDEWKKKEKKKWKKWWKjfKWWW#WWWWWWWWWWKWWWKWWWWWW##Lj;              i#.                     //
//  #      :#D    ##    i i              jDEEKEEWWKKWKWKWGDjjDDWW#WWWWWWWWWWWWWKWW##WW####ft,             ,#.                     //
// ##       #    #  L jD                ,GEDKEEWWKKWWKK#WjjtfD##W##GfEWWWWWWWWKWW##WW######Et;            :#  ##                  //
//#             #   :#G      ,     ff;  jEKKEEEWWWWKKWKKKDGDiLKWW##GfLKWWWWK#WWW##WW#######KDL            .   :#                  //
//        ##   ;    W    ####     fDGifLfWKKKWWEEKEWKKKWKEtGjtGEK##EffLLGWW#WKW#############DDi                ##                 //
// #      #  # .   .#   ###      .j  .tGGEEEWKKKKEKWKEWW#WfKELKKKEGDWLffKWWEEEK########W####KEj:               ##D                //
//       G  G  ,##  #  ####      LG   GEDEEKWWEEKEEK#EEW#WWEEEKKEWfff:fKWKEEEEEEE##WWKEE#W###Kff               ###                //
//            #       #####      j    iDEKEW#KWEEEWK#KEW#W#KEEEEEEEEEfWfEWWWWKEEEKWEEEEEWWW##WL;               ###                //
//G      ###  D      #####       t     GWKEKWWWEKKWK#WEWWKEWWWWWWWWW;fWGfWWKKEEEEKWKEEKKEW###WL;               ####               //
//L     K           K####        f    KWWEEK#WKKEKEKWWKWKKKW#W#WWKEKDLWKK#WKKKKKEKKKKKWKKKW###Df               :###               //
//     K           L####         G    KWKWEWWKWWEEKWKKWEKK###KKKWWWWWWWK#WWWKWKKEKK#KKKKKKW###DD                ####              //
//    ,            K####   W#WWWKEEEE. WKWKKWWKEEKWEKWWEKW##WKKKKKWKWWWK#WK###KKK#WGWKKEEE#WWWEEi               #####             //
//   i            E####  #WWWWWKKEEDEEDGWWWWWWWKWWEEWWEEKW#WWKKKKKKKWWWKW########KWWGDKKEEWKWKKE,:              #####             //
//     i         :K###   WWWKKKKKKEELjLGGW##WKKKWEEKWEKKW#WWKK#######KW############WGGEGW#W#WWt,,               ######            //
// .  #          K###D  WWW#    tG KffLGDKKWWWKEEKWWKWWKW#WWWGG######WWW#####W######WWWWWW###Li,:               #######           //
//#             KW###   W#W     tL WWWKGDK#WWWWKKWWKWKKWWW#KGGG########KKWWWWWW#######WWW#WWWfi,                ######W#          //
//G            fWWW#W   #WW     ft  WW#WWW#WWKKWWWWWKKWW##KDGGG#######KKKKKKKWKD#####WWW##WWWWt;                ###D###WL         //
//             WWWWW#   #W      Lt iEWW##WWW#WKKWWWWWWW##EGDGGGD####WKKKKKKKKWGE####WWWWWWWWWWWj,               ###G###KK         //
//            KWWWWWW   WW      LtLfL#W###WWWWWWWKKKW##KjGGDGGGG###KKKKKKKKKGGGKG###WWWWW####WKf                ###D#G##EK        //
//            WWWWWWW   #W       tjfWK#####WKK#WW#W###KWfGGDGLLGW#KKKEKKEEKGGGGDGG###WDGG####WK                 ##KGE###KDK       //
//           WWWWWWW#   #W       ttK#j#######W#W#####GGGfDGGLffDDWKEEEKEEWGGjGEGGG#GDGKGGLW###D                 ##GGG#G##DDK      //
//          WWWWWW#W#    WG      itW#f#######KW#####KGKj;fDjtLjjGLjK###WWGEGfjGGGGGGGGDLLLWWWKDDj               ##GGG#GG#WDDf     //
//         ,KWWWKWW##    WW      :tjWjK#####EDDDEK##GDDj;tDtGLjtLLttLjGLiDfftttDfijGGjGLLfjKW#KEEL              ##GGG#WG##KGE     //
//         KKWWWKWK##    WW        fLEfG###EEEDGGGGDGKt;;;;DjiitEitttGLEt;tjtttji,;jfjDLfLtDKWKEL               #DGGGG#GG##DGK    //
//        GKWWWE#WE##     W         KjLDGWDGGGGLLGGLjKtjffjjjij;i;i;;ifji,it:;ffGi;jGjGGL,tjGW#i     ..        ##GGGGD#GL##WLGK   //
//        EKWWEGWDD##     WW       WKfjLGGGGLtDfDGGKfKK##WWtjtDit,;t;i;Lt,LKWWWWEtifGjGGL;:tfi:        :       ##GGGGG#KLG##DLEj  //
//       GKWWWGGWDE##t     KW     ;KEEKfDGLjDLLfGGjttGD#W#W##EjEttttiiE,DEWWW#WEiittLjDGGj jj:         ::     ##DGGGGGD#LLL#KGDK  //
//       EKWWLL#WEE###     WWW   iEE E  i,DLLLffLLjtjjt#KWWWKKtGtittiijELKEKWWKttittGjGfLL;Ljj         .:     ##GGGGGGG#GLL##ELDK //
//      jKWWWLGWWEE###      W##  ;iKfE  tWGGLLLfjLtitf,EDEDDE;GjitjitjijiWEELDKtifitGtEfLGLGfft         ,:   L##GGGGGGG#GLLL#EDDK //
//     jDKWWGLL#WEEE##       #W# ;i KK  LEGGffLjLffttGf,ftfjL,,f;fttfttL,,ffjj;EifiijfGffLGLLfG         ,,   ##GGGGLLLLE#LLL#WDEDW//
//     jKWWWLLLWDDDD##        WW#jiiKG jGGEELLEjEjttiijWttjjj,,,i,jitjijj,jffDjELfitifGGLLEGLL.t        ,:, f##GGGLLffLL#LLLL#EDDK//
//    jLKWWWLLKWDDDD##        #WWWfjjjDGGGGELfGjLtttttiiGiL;,,,,,,;,ifLtt;;GiEiDifiGGGELLLLKGD L       :,f. ##GGGLffffff#LLLL#KDEE//
//    jEKWWLLf##GGDD##         WWW WW tiWGGELfjKjttttti;i;;;;,,,,;:;,t,,ji;;;;;DGjtLDGKfGLLGDDDG       ,;t G##GGGfjjjjff#KLLLL#DEE//
//   jjKWWWLLfW#GGGDK#          #  W# f GGGELG.GjDDtitj;;;;;;,,,;;,;;,i,,;;;;;;tDjfGGfDGLDLGGLLDL;  .:,,i  ##GLLfjjjjjjjf#LLLL#KEE//
//   jDWWWGLfjW#GGGDD#             W  L.GL DfLjLjtDittti;;;;,,,,;;;;;,,,,;;;;if;DDjjGjjGLKGLGGLGDjjjti.   .##ffjjjjjjjjjj#fLLLL#EE//
//  jjEWWWffjjW#GGGGD#            WW :tGLG GfjGiDtDjiiGf;,,,,,,,,;;;;,,,,,,,,,GtGGtjLjjGLGELLLKLLD        #Wjjjttttttjjjj#fLLLL#KE//
//  jjKWWWjjjjWGLGGGG#W        ,, KW iLGD :fjjLGGjjEtiijti;,,,:,,;;;,,,,,,,,,;;KjjjjGjjELGKDGLLEGLt      :#WjjtttttttttjjL#ffLL##E//
// fjDWWWjjjjjWLLGGGGG#       ;:  K  .GGj ,jtjDDjGjjttiiti;:::,,,,,,,,,,,,,,:iEKtjtjEfjKLKLG LLDj fj     #Wjtttttttttttttj#ffLf.#K//
// jjKWWWjjjtGWLLLLLGG#       ;  GK , LL: ,;tjfDjtDtjttfij;,:,,,,,,,,,,,,,,,:jELtGtjEffKGDLW ;LDj   ji  .#ttttttttiiittttt#fffff##//
//;jfKWWWtjtt#WLLLLLLG#      ;,  WK ;,Lf ;,,LjfGjjjEftGifit:,,,,,,,,,,,,,,,,,iL:jfjjLjLKGGD   GGt    Ej #EttttittiiiiittttGffDfff#//
//fjEKWWtttttWWLLLLLLGDW     ,,  KWjj Lj ;,.;jfffjjfLttDDfj,,,,,,;,,,,,,,,,,fWfjjjjLffWGDGL  :DLL    jDK#jttttiiiiiiiiiiW;i#fffff#//
//ffKKKWtttttWWfLLLLLLD# #    ;  K fj Lff;,  fLfLjjjfLLiDDji,,,,,,,,,,,,,,:G#EffLjjEffWGGL.   ELE    GfED#tttiiiiiiiiii:,,;Wfffff#//
//fDKKKKtttiiWKffLLLLLf#W#     ;WKff; GLj:,:ttLLLDjjjLGLLDDEi,,,,,,,,,,,,:#EGGLfjjDGffLLLL.   jDD    DjjGLttiiiiiiiiiW::,,;#ffffff//
//LEKKKtttiiiKKffffLLLfL#       jLfjfLGLj;,,jtffLLEfjjLLLLDDDD,,,,,,,,,,GWWLLLLDjDDLfEGLft,.:.tEG    Gj,iLKtiiDiiiiit,,#,,;DEfffff//
//GKKKKttiiiiKKjffffLLf##       K,fj:jDtff;jij fLLLDfjjfGGGLGEWK,,,,,,DLj,#LfEGKjfDffGLLG ,:  ;LK    Gj:tLLti#Kiiit,:,i#,,;t#fffff//
//DKKKKtiii;;KLjjjfffff#LW     WK jjLt: ,j;tt  EfEfEGjtGjLLfEDDEEDfGDLLjj:#GfLLLjGfD ffLL  ,. ,fK   #ft:jLLDt#WiiE:::,#K,,;i#jffff//
//EKKKtii;;;;Etjjjjffff#fKW    WK  Gjt : tftt,.GfGGDDGfitjGLDDDDDDLfLLjff:WGiLLLGfitLLDLf   ,:;Gt   #f,tLLLfi##i:::::f#,,,;i#ffjff//
//KWWKtii;;;,Etttjjfffffff#K   KW   fDLDjtij,jiGjDjG:G jLtGLDWEDDGLffjjfffWD;GLLL  .LL Lf,   ::G   #jjtLLLffW#E,,::::#L,,,;i#jjjjf//
//WWWWti;;;,,EttttjffffffffLW KK.   jGjfjt;.   jjGjjf.: ijLtLWEDGGLjjjjffWWGDDDfGD  fL  LK   ,;ff ##LjGLLLfffK:,:::::W:,,,,i#jjjjj//
//WWWEii;;,,,DttttjjfffffffifWWK   .j .t:   iLDjL;GjDffjtjjLDKWDGGjjjjjjWWWDGELGGLL fL   DGi,,  iDWKEDLLLLfft,,,:::::D::,,,i#jjjjj//
//WWWti;;,,,:DiiittjjfffffGiiiKW.  fG    fiiLji;,;ttGLfffLjEKEEWGfjjjjjKEKWWGjDfL :Lf ::   L;    WDEDGLLLLL,:,,:::::::::,,,i#jjjjj//
//WWWti;,,,::DiiittjjfffffLiijKWG#Kt   Diii,t;,,,,,tD,ft:fDKEEEEEjjjjEEEEEWWWEiffj  fGLLL.  GE  ##KDDLLLLL,,,,::,:::::::,,,;#jjjjj//
//WWWt;;,,:::GiiittjjffffDiiiWKLLfftW .iii;;j;,,;,,tDL;;;iKKEEEEEEffKEEEEEEWWWtGLfEGDLjfG.   iK##KEGLLLLL,,,,::::,,:::::,,,K#tjjjj//
//WWti;,,,:::GiiitjjjfjjWiiiiKKLLfGGGLi;ii,,jL,,,,Etf,,fii;iEKKDEED;;;WKEE#DtttttttttLfjjffD; #KWEEDiLLf,,,,:::::::;,::::W,;WtLjjj//
//WWti;,,,:::GiiitjjjffWiiiijKWLLLtGGG;;i;,,jji,,Ejf,,,,,j,iGW;;EE,;;t,:#WWftiiiiiiijfDKGtiLi###EEELfLL,,,,,:::::::::j::,,i;WLLLKj//
//WWi;;,,::::GiiitjjjjWiiiiiWKLLLGtGWKKKKW,,,ttttttL;,,,,tWEKEG,E;;;E,,,fEEEEt;i;,,,,iiiGLiiDi#KEfLLLL,,,,,::::::::::::,,K,;WffLLL//
//WWi;,,,::::GDiitjjjWiiiiiiKKLLLtLGKKKKKKKKG,LtjtD;;;,,,KEDDD;;;;;t,,,,,EEEEW,,,,,,,,iiiDiiiifGLLLLL;,,,,::::::::::::::;,,;GfffLL//
//Wti;,,:::L.G:GitjjW;ii;;;iEKLLLtLKKKKKKKKKKW,,;;;;;;,,,EDEDDE,;;t,,,,f;#DEDK,,,,,,,,,iitt;iDfGfLLL,,,,,:::::,:::::::::,,,;jfffff//
//Wi;;,,::f..G::,GGL;iKKKKKKEKLLGjWKKKKKKKKKKK;,,ti;i;,,,KDEKKK,t,,,f;,,,,LEE,,,,,,,,,;;iiijiiiGLGL,,,,,,::fWWWW::,::::,::,,ffffff//
//Wi;;,,,:...G::,;,i;KL    EE.W#tKWKKKWWWKKWKKK,:jtii;,,,iEEEDDL,;;,,,,,,,:EE,,,,,,,,;;;iiiif;iLLGi,,,,,WWWWt   .WK:::::::,,tfffff//
//Wi;;,,:....G:,,;;;K      DE  LjWKKKKWWWWKKWKKtWWDii,,,,,EEDDDK,t;,,,,:ti,D,,,,,,,,,;;;ii;;;f;iLti,,,#WW          ;,:::::,,,jffff//
//KE;;,,j....D:,,;;K:      EE  tKWKKWWWWWWWWWW#WKKWii,,,,,,KDE#K,,,,,,,,,,,;,,,,,,,,,;;ii;;;;;;;WWW;,#               :::::,,,jffff//
//K;G;;E:....D,,,;;K       EK  tWKKKWWKKKWWWW##KKKKE;,,,,,,fEWWW;,,,,,,,,,,i,,,,,,,,,if;;;,;;;;i###j:                 ::::,,,jjfff//
//W;;;,......f,,;;;f       E  jtWWKWWKKKKW#WWWWWKKKEi;,,,,,,WWKW;,;,,,,,,;;E,,,,,,,,,;t;;,;;t#WWWWW                   :,::,,,jjjjf//
//K;;;:::::..:,,;;t       KE  tLWWWWKKKKKWKWWWWW#KKKK;,,,,,LKEKEj;;,,,,,G,;WW,,,,,,,,,t;;,;WWWWWWWWWE;                 W::,,,jjjjj//
//W;;;:.::::..,,;;K       KK Dj .WWWKKWKKKKWKKWWWWWWWG,,,,fEEEKED;;i,,,E;,WKEf,,,,,,,LL;;KKKWWWWWW#WDt                  i:,,,jjjjj//
//K;;;::f:::..;;;;        KK jfiKKWWKWWKKKKKKWKKK#WWKKE;;GDEDDKWG;;i,,;iWWKEEE,,,,,WKKKiiKKWWW##W##Wj                    :,,,jjjjj//
//Ei;;::,::::.i;;;        KKGt,KKKWWWWWKKKKKKKWWWWWWWKWjtDEEDDKWG;;;,,;;iWKEEEt,,jKKKK#tEKKKW###W#WE                     K,,,jjfjj//
//ji;;::::,:::E;iK        KKjt EEK#WWWKKWKKKKKKW##WWWWWLEEEEEDEjDi;;,,;;;WKEEEE,jKKKKWW#WWWKW#####WK                      ,,,jKKKj//
//tiiG,,:,,,:.:;K         KKjL GDEWWWWWWKKKKKKKKW###WW#WDEEE####ijii;;;;;#EEEEEKEKKKW#WWWW#W####WWWKK                     E,,jW Wj//
//iiiE,,,,,,:.G;K         WKE   DEWKWWWKWKKKKKKKWW#WWW#WEEEE#####iiiii;;;WEEEEEWKKKW####WW####WWWWWKKW                     ,,f D K//
//iiiK,,,,,,,;KtK         DKD    EWKWWWKKKKKKWKKKWW#WW#WEEEDKK####iiii;;;EEEEEEWKKK#########WWWW##WKKK.                    ;,j   W//
//tiiKKK:  K;;;tK         LKD    KKKWWKKKKKKKKW#WWW#KWWW#EEW#KE#W#jiii;;#EEEEE#WKK########WWW####WWWWWK                     ,K   W//
//jtEK      .;;i          jKE    EKKKKKKKKKKKKKW#WWW#W##W#EE#KKWK#itW##G#EEKWW#WWW###W##W#WW###WWWKWWWK;                    tW   ,//
//fDK         ;E         GjKEK  iKKKKKKKKKKWKKKKWWWW#W#WK###WWWKKW#W#KKK#W#W########WKWW#WK##W#WWWKKWKKf:                   D     //
//fW          Ei         fjfKE ,KKEKKKKWKKWWWWWKK##WWW#WKKK#KKWKKKKKWKKWKWKWWW###KKKKWWW#WW#KK#WWWKKKKKE;;                  KE    //
//fW           W         jj KK DKEEKWWWWWWWWWWWWKW####W#KKKKKKEWKKKKKWWKKKWWKKKEEKEDEW#WWK#WKKWWWWKKKKKEE;,.                E     //
//W                     :jG KKDKEEKKWWWWWWWWWWWWWWWWW#W#KKKKWKEEEK#WKWWKWWKKKEEEKEEEKWWKKW#KKKWKKWWKKKKKEK;,,                     //
//W             :       jj   DDEEEKWKEKWWWWWKWWWWWWWWWW##WWWWKEEEKKKK##WWWEEEEEEEEEEKWKKKWWKKKKKKWWKEEEKKEEEL;                    //
//#             G      Gjj  iDDDDKKKEEWWWWKKKKKWWW##WKWWWWKKW#KEKWWWWWKWWEEEEEEEEEEEWWWKK#WKKKKKKW#WKEEEEEEEEKED                  //
//                     fjD  LDDEEKKEEWWWWWKKKKKKWW######WWKK###WWWWKWWKWWEEKEEEEEEEEWWWKKWKKKKKKKW#WKKEEEEEEKKEEEE                //
//                     jj  .GDDKEKKEWWWWWWKKKKWWWW####W##WKKKK#K####WKKKWWWWKEEEEEEK#WWKWWKKKKWKKK#WKKEEEEEEKKKKEEi               //
//                     jj  ;LDDKEKEWWWWWWKKKWWWWWE########WKKWWKK##WKWWW#WWWWEEEEEEEWWWK#WKKKKWKKW#WKKKEEEEEKKKEEE;               //
//           #        Gjj   fDDKKKKWWWWWWKKKWWWWW########W#KKKWKKWKWKKKKWWWWKEEEEEKEKKWW#KKKKKWKKWWWKKKKEEEKKKKKEE;               //
//.         K         LjG   LLDDEEWWWWWWWKKWWWWWWE#######Eii#KWKKKK#KKK#WWWKEEEEEEKWKKWWWKKKKWWKKWWWKKKEEEEKKKEKKE,               //
//D         W         jj     iDDEKWWWWWWWKWWWWKKKW#######iiiiKKKKKKWKW#KWWKKEEEEEEW#WKKWWWKKKWWKKWWKKKKKEEKKWKEEKK,               //
//W                   jj      GDDKKWWWWWKKWKE###########;iiiiiiWKKKWEEEKWWKKEEEEEKW#WKW##WKKWWWKKW#KKKKKKKKKWKEEKt,               //
//W                   jj       LGKKWWWWW#####KWWWW####j;iiiiiiiiKEKWKEEWKWWKEEEEKK##WKW###WKWW#KKW#KKKKKKEKWWKKKEt                //
//W                   jf        KKKWWWWW######KWWW###;;;iiiiiiiWEKKKKKW##WKWKEEEK##W##KW###K#W#KKWWKKKKKEEKWWKKKKj       #        //
//#                   jL       EKKKWWWW#######KWW##G;;;;;iiiiifEKKKKKWWW#WKWWEEKK#WWW##K###W#K#KKWWKKKKKKEKKWKKKKf       #        //
//#                   jf      fKWKWWW#K########WW#;;;;;;;;;iiiWKKKKK##WW#KW#WWKE##WWWW######WK#KW#KKKKKKEEKWKKKKKK:  :,j##        //
//#                   jf      GGWWWW##K#########E;;;;;;;;;;iifKKKKKK#KW##KW##KE#####WWW######W#KW#KKKKKKKKKWWWKKKKWi;;DE#         //
//#                   fj      jELWWW##K########;;;;;;;;;;;iiiDWKKKK#WWW#WKK######W##WWWW#W###WWKWWKKKKKKKKKWWWKWWWKKiEE##         //
//#                  :ff       fEDWWW#W#######i;;;;,;;;;;;iiGWWWKKW#KW##KKKW#######WWWKKK#####KWWKKKKWWWKKKWWWKWKKWKKEEKG         //
//#j                  ff         DEKWW#W#####i;;;;;,,;;;;iitWWW#KK#WKW#WKKKK####W##KKWKKKK####WWWKKKW##WKKKWWWKKKKKKKEEEK        W//
//:#                  ff          iWWWK#####ii;;;;;,,,,,,iiKWWW##WWKKW#WKKKKW##K##WKKWWKKKK####WWKKKW##WKKWWWKKKKKKEEDEEE        #//
// #                  ffj        GEEEEKKW###i;;;;;;;,,,,iij#######KKK#WWKKKKK#WWW#WKKKWWKKKW####WKKW###WKKWWWKKKKKKEEEEGG        #//
// #                  ffD        EWW##WKK##i;;;;;;;;,,,iitW######WKKW#WWKKKKK##WKKKKKWWWWWWWWW###KW####WKKWWWWKKKKKKDDEGD        W//
// #                  Lff        KW########,;;;;;;,;;;;ii#######WKKK#WWKKKKKKW#WKKWWWWWWWWWWWW##WWW###WKKWWWWKKKKEEEDDGGEKG     WW//
//                    Eff        j#W#######;;;;;;;;,;;iiG#######KKKW#WWKKKKKKW#WWWWWWWWWWWWWWWW######WKKKWWWKWKEEEEDDGEKKKK     W //
//  #                 .ffD        DWG#####W;;;;;;;;;;;i########WWWKKWWKKKKKKKWW#WWWWWWWWWWWWWWWW####WWWWWWWKKKKEEEEDDKKKKEK     W //
//  #                  fff       KWW#G####i;;;;;;;;;;t########WWWWKKKKKKKKKKWWW#WWWWWWWWWWWWWWW####W#W##WWWKKKKEEEEWKKKKKKE    iW //
//                     fff       WWEKKD###;;;;;;;;;;E#########WWWWWKKKKKKWWWWWWWWWWWWWWWWWWWWW########WWWWKKKKKEEEWKKKKKKKK    WtK//
//                     Efff      fWW##D###;;;;;;;;D##########WWWWWWWWKKKWWWWWWWW#WWWWWWW###########W#WW#WKKKKKEEWWWKKKKKKKK    W# //
//   #                  Dff      EWW#W####Lii;;;iW#########WWWWWWWWWWWWWWWWWWWWWWWWWWW############KKKWWWWKKKKKEEWWWKKKKKKKE    W  //
//                        GD    L#W########ti;##W#########W#WWWWWWWWWWWWWWWWWWWWW#WW#############WWKKKWWWWWKKKEWWWWKKKKKKKL   W#  //
//                            DWWWW############WW#########WWWW#WWWWWWWWWWWWWWWWW#################WWKKKWWWWWWKKEWWWWKKKKKKK    #   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
