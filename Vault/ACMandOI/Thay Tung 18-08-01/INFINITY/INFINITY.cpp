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
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));
/*************************************************/

/************** [BITWISE FUNCTIONS] **************/
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
#define OImode 227420978

//#undef OImode // Switch this off if submitting OI problems.

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
typedef pair<pii, pii> ppp;
i64 m; string n; ppp N;
/************************************************/

/************** [FUNCTIONS] **************/
ppp add(ppp a, ppp b) {
	ppp res = a;
	res.fi.fi += b.fi.fi; res.fi.se += b.fi.se;
	res.se.fi += b.se.fi; res.se.se += b.se.se;
	res.se.fi += (res.se.se / INF); res.se.se %= INF;
	res.fi.se += (res.se.fi / INF); res.se.fi %= INF;
	res.fi.fi += (res.fi.se / INF); res.fi.se %= INF;
	return res;
}

ppp subtract(ppp a, ppp b) {
	// guaranteed that a >= b
	ppp res = a;
	res.fi.fi -= b.fi.fi; res.fi.se -= b.fi.se;
	res.se.fi -= b.se.fi; res.se.se -= b.se.se;
	while (res.fi.se < 0) {res.fi.se += INF; res.fi.fi--;}
	while (res.se.fi < 0) {res.se.fi += INF; res.fi.se--;}
	while (res.se.se < 0) {res.se.se += INF; res.se.fi--;}
	return res;
}

ppp multiply(ppp a, ppp b) {
	ppp res1 = a, res2 = a, res3 = a, res4 = a;
	res2.fi.fi = res1.fi.fi * INF + res1.fi.se; res2.fi.se = res1.se.fi; res2.se.fi = res1.se.se; res2.se.se = 0;
	res3.fi.fi = res2.fi.fi * INF + res2.fi.se; res3.fi.se = res2.se.fi; res3.se.fi = res2.se.se; res3.se.se = 0;
	res4.fi.fi = res3.fi.fi * INF + res3.fi.se; res4.fi.se = res3.se.fi; res4.se.fi = res3.se.se; res4.se.se = 0;
	
	i64 multiplier4 = b.fi.fi, multiplier3 = b.fi.se, multiplier2 = b.se.fi, multiplier1 = b.se.se;
	
	res1.fi.fi *= multiplier1; res1.fi.se *= multiplier1;
	res1.se.fi *= multiplier1; res1.se.se *= multiplier1;
	res1.se.fi += (res1.se.se / INF); res1.se.se %= INF;
	res1.fi.se += (res1.se.fi / INF); res1.se.fi %= INF;
	res1.fi.fi += (res1.fi.se / INF); res1.fi.se %= INF;
	
	res2.fi.fi *= multiplier2; res2.fi.se *= multiplier2;
	res2.se.fi *= multiplier2; res2.se.se *= multiplier2;
	res2.se.fi += (res2.se.se / INF); res2.se.se %= INF;
	res2.fi.se += (res2.se.fi / INF); res2.se.fi %= INF;
	res2.fi.fi += (res2.fi.se / INF); res2.fi.se %= INF;
	
	res3.fi.fi *= multiplier3; res3.fi.se *= multiplier3;
	res3.se.fi *= multiplier3; res3.se.se *= multiplier3;
	res3.se.fi += (res3.se.se / INF); res3.se.se %= INF;
	res3.fi.se += (res3.se.fi / INF); res3.se.fi %= INF;
	res3.fi.fi += (res3.fi.se / INF); res3.fi.se %= INF;
	
	res4.fi.fi *= multiplier4; res4.fi.se *= multiplier4;
	res4.se.fi *= multiplier4; res4.se.se *= multiplier4;
	res4.se.fi += (res4.se.se / INF); res4.se.se %= INF;
	res4.fi.se += (res4.se.fi / INF); res4.se.fi %= INF;
	res4.fi.fi += (res4.fi.se / INF); res4.fi.se %= INF;
	ppp res = add(add(res1, res2), add(res3, res4)); return res;
}

ppp makeCluster(i64 z) {
	ppp res = mp(mp(0LL, 0LL), mp(0LL, 0LL));
	res.se.se += z % INF; z /= INF;
	res.se.fi += z % INF; z /= INF;
	res.fi.se += z % INF; return res;
}

i64 toI64(string z) {
	i64 res = 0;
	for (auto x: z) {
		res *= 10;
		res += (x - '0');
	}
	return res;
}

ppp makeCluster(string z) {
	// standardized strings, length 36
	ppp res = mp(mp(0LL, 0LL), mp(0LL, 0LL));
	res.fi.fi = toI64(z.substr(0, 9));
	res.fi.se = toI64(z.substr(9, 9));
	res.se.fi = toI64(z.substr(18, 9));
	res.se.se = toI64(z.substr(27, 9));
	return res;
}

i64 sqrtI128(ppp z) {
	i64 top = 1, bot = 1e16, ans = LINF;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		ppp M = makeCluster(mid);
		ppp sqrM = multiply(M, M);
		if (sqrM >= z) {ans = mid; bot = mid - 1;}
		else top = mid + 1;
	}
	return ans;
}

void Input() {
	cin >> m;
}

void Solve() {
	while (m--) {
		cin >> n; n.insert(0, 36-n.size(), '0');
		N = makeCluster(n); i64 segment = sqrtI128(N);
		if (multiply(makeCluster(segment), makeCluster(segment)) < N) segment++;
		ppp ID = subtract(N, multiply(makeCluster(segment - 1), makeCluster(segment - 1)));
		i64 id = ID.fi.se * 1000000000000000000LL + ID.se.fi * 1000000000LL + ID.se.se;
		if (id <= segment) cout << id << endl;
		else cout << (segment - (id - segment)) << endl;
	}
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

/************** [MASTER CONTROLS - PHASE 2] **************/
void ControlIO(int argc, char* argv[]) {
	#ifdef Akikaze
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
	freopen("INFINITY.INP", "r", stdin);
	freopen("INFINITY.OUT", "w", stdout);
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
/*********************************************************/

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
