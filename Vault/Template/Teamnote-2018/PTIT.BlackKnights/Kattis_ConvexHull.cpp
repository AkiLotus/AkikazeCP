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

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/** -----CUSTOM TYPEDEFS/DEFINES----- **/
i64 cmp1(double A, double B) {
    if (A - B < -EPS) return -1;// A < B
    if (A - B > EPS) return 1;// A > B
    return 0;// A = B
}

struct point {
    double x, y;
    bool operator < (const point& that) const {
        if(cmp1(x, that.x) != 0) return cmp1(x, that.x) < 0;
        return cmp1(y, that.y) < 0;
    }
};
bool cmp(point a, point b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool cw(point a, point b, point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw(point a, point b, point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
void convex_hull(vector<point> &a) {
    if (a.size() == 1)
        return;
    sort(a.begin(), a.end(), &cmp);
    point p1 = a[0], p2 = a.back();
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back(up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back(down[i]);
}

/** -----GLOBAL VARIABLES----- **/


/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
}

void ProSolve() {
	i64 n; cin >> n;
	while (n != 0) {
		vector<point> a; map<point, i64> Map;
		for (i64 i=0; i<n; i++) {
			point pts; cin >> pts.x >> pts.y;
			if (!Map[pts]) a.pub(pts); Map[pts]++;
		}
		convex_hull(a);
		cout << a.size() << endl;
		for (i64 i=a.size()-1; i>=0; i--) cout << a[i].x << " " << a[i].y << endl;
		cin >> n;
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
OOO###$-^`^^.--~~~-.~~~~~-.^~~~~__~:++;+;~^^^^-!%eiiio?O##?i==e####!iiiii:.^^
##OO##$-^`^^.-~~~~~..~~~~~.^~~~~__~:+;;;;~^``^-*!!**o*e$##!=++*O###e=====:.^^
##OOOO$-^```.~~~~~~..~~~~~.^~~~~-_~:+;;;;~```^-e!eee**e$##!+;;oO###*====+_^^^
###OOO$_^```^~~~~~~..~~~~~.^.~~~-_~:+;;;;.```^-?!ee***e$##e;;;oO###*+++++_^`^
######O_^```^~~~~~~.......^^...~--~:;::::.````~ee***ooe$##e;::iO##Oo+++++-^``
####O$%_^```^.^^^^^^^^^^^^^^^^^^....~~~~~.````~;;:::::;=ii+_-_;o***+:::::-^`^
O$$O$%e-^```^^.~....^.....^^.....^^.^^^^^^````^......^....................^``
i++iiee-^```^.-;__:_.-:__:~._:-__..-----.^````^~-~~-~.~-~~-..~~~~..~~~~~.^^``
:::;;i=-^```^.-;_-;_._;__;-.:;_:;~~::_:_.^````^-:__;-._;_:;~~___;-.__-::.^^``
+;;;=i;~^````^-_--_-.-_--:~._:-__.~__-__.^````^~_--:-.-_-::.~_--:-.__-__.^^``
ii=io*+~^````^-:--:-.-:__:-.__-__.._--_-.^````^~_--_~.---__.~_--:~.__-__.^```
ee*e!!o-^````^-:_-:_._;__;-._:-::.~:_-;_.`````^-;__:-._:-::.~;__;-._:_;:.^```
??????e_^````^~~~~-~.~-~~-~.--~--.._--_-.^````^~_--_~.-_-__.~:--:~.__-:_.^```
%%%??%!;^````^^^^^^^^^^^^^^^^^^^^^^^^...^^````^......^.....^......^.....^^```
%%%%?%%o~`````````````````````````````^``````^^``^^^^^^^``^^^^^^^^^^^^^^^^```
$$$$%%$!:^``````````````````````````````````^^```````````````````````````````
#OOOOO$%o~````````````````````````````^^^^^..^`^^^..^``````````````````^^^^^^
#####OO$!_^``^^^^^`^...^^``````````._+++++-~-.^.^..-.^````````````````^..~--:
O######O%:...-____-_::_-~~~~-~.~~~_=ioo*eo===;_~.~~--~^^^^^^^^^^^^^^^^~--__::
OOOOO##!:~^^.;!!?????o;__++===o*i:;+ii*!**oooi==;:_--:_:+=iii====;:;;__:+;__:
OO%%$O#e~^^^^:!!$OOO?e=:__;+::_*=ii===oo**e***o*ooi;_--:=?%!!!!eo;:+;__;++;:;
#O%?%$OO+.^`^:?%%##$i;::::_____oe!!?e*==oo*e**ee!?**+-_:_=oe!ee?=;;+;;;++::+=
##OO$%$O%_..~+??!%O?+;______:_=!?!$$?%!eo*****?!$!?!e+;:_:;o*o*!i;:;;+=+:_:;+
#OO$?!?%$eiio*ooi==+::_:__;::;!%$$O$$$$%!e***!!$!%O$!oi:_;;ooiio*+;==+i+;+=ii
$$?e*o*e!!!*o=;::;:_-__:::-::o$OOOOO#OO$$%!!ee%?O#$!!o+;::+i=+++=;++;+=+=i==o
%?!*i=ioooo=+;:_:+=:__-___-_:%O#OOO###OOO%%%$$$OO$?%%=-_::_::;::::;;::::++++*
OO%?*+;=o!e*o=+;;==:__:__--_iOO#######O#OOO##OO$$%$O?+_.:__;;;--;=i=++===++o!
#O!i+;;:;+;:;+==o=:--_::::__?###O############O$OO#OO*+:.~__;=;--e$eo!!o*oiii=
O?*=;:;;:_~~-~-_;__--_;:_::;O###############OO###OO!=;_-~-__i+__!O*+;:+ii=i_.
??!*=+=;;_-~~~-_:;+;_;+:_;;*##############&######O?*+:__----____ie=;_;+=+::.^
e$e!*oi;:__--_:;::;;::+;:;i%#############&&######$!i;:_____-:;__=;-_::_:_~-~^
*O?!ooi+;:_~-_---_;;::=+_;oO#####&####&#&&&#####?o+;:____;:__:-:+_--::__-.^^^
*#Oe++;;__:~_;__:;;;+:+i;;o##########&##&&&&&&#%=;;:__;+;=;_-~~_--__+;:::.^^`
eO$o+;::_;=+i=++;:-__;io;:*#########&##&##&&&&#e;::::=*%!o=:--:__::;++;+=:~^^
eO%=;+===*e?%*=;:__:;+o!+_?#####OO####&#O#&&&#$i:::+o*=oo=::__;:_-+=+:+;_:_.^
e$%=+oe*o?$?oo;-~~_:;o*e*e$#####OO######OO###O!=:_:=?%%*i+;;_--:+;o**;o=_~..^
e$%e**!*?%!;-_i+-~_++**oe?$O###OO####&&##%$#O%*;:___i?$o+:;_-~_oiii=eieo=;-^^
!$%!e!ee!?i++_:;+;===o*o=$####OO##&&&&&%O??$%?o;__-~-==_:_;=:;++i++io!$!+:-^`
!%?*o!!ii+_==::;i=;e!*e*?O######&&&&&#&%??!?%?i;:__-~-----;e=:+====*!*!%;~.~^
e%?*ioi*!++*?oo=e*;ooieo?O###O#&&&&&&&&%!!e??e=;;;;:_--_~:;=__+;;:;e!*+!i.^~.
e%?eoi+o***e!e%!$%ii****%O#####&&&&&&&&Oeeee!o+++;+=+_-:~:;_-::_;;;oi;_=i~^^^
!?!!??*=ie?ooe?oo=_-:i*!O#####&&&&&&&&&##$e*o=;;++=++:;_:;i;+;+io+;ii;~_;;_:;
!ee?$%i=o!i+=*!ei-_::;;?O####&&&&&&&&&&##$ei=+;;+++=+;oi*=;-i*=**++oi:~~_;;=o
!?!%$?=o?%o*%e!%=_+==++?OO###&&&&&&&&&&#O$!i=+;;++==i+oe=:+:??oo*===+;-.~_+*!
!%?%O!i?#O###$%$!e!*=+*$O###&&&&&&&&&&&#$$!o=++++==ii=;io+i*%!oooi==i::~~~_!%
e??%$?=i%###Oo*%$!o*ee?$####&&&&&&&&&&&#$%?*i=====iooeoo==oeeooo+!?!oo=:___*$
e?%%%?==!###?=e$!o=o%$$O###&&&&&&&&&&&&#$??eo====ioo!?*i+=oi=++o!eeoi=~:;;:+!
e?%$$%o*$###O!%?eo*e$%$####&&&&&&&&&&&&O???e*i==iio*o*o+====*!+o$!oi=_^.-:===
?%$##O%%O####OO%?i*%$$O###&&&&&&&&&&&&#$!??!eoiiio**iiiio*ooe$*?#!eii;-~_+oi=
%%$#&#OO#######O!!%?$O###&&&&&&&&&&&&&O?e!?!e*oio*ooi+++o!e!e$?$O?!+i****ee*o
??$###OOOOO####$!$$%$?###&&&&&&&&&&&&&%!*e?!e*iiioooi;:=ie?%%$O!%e*+o?%?*ooii
e%O#&#O$OOO$O##O$OO$!?##&&#&&&&&&&&&&O?**e!!e?%oiiioo-_:+??$%%?=o!o+:+i+:_---
?$O###OOO#$?%O##O$OO$O##&#&&&&&&&&###%e*o*ee!%**%e:i=.:=*??%?!?eoei:-_:_~~~..
O$$OO##O##$!e%OO$$OO$##&###&&##&####%!*oo*ee%%%%$?i*e=o;oe!%?ie!o*=:___----~~
#$%?!?O#O%%!e!%$%!!$O##&##&&####O##%eoiio**??!%$#O%!!*ei;=;i?e??e*i=++;;;++::
#Oe-.:$#$%?????!!o=?##&&#&&###O$##!i+==io**?%?$$O#%??!=i=+:-o%O%!o!%?!e!!?!ee
O?-``:%$$%%%??%?!=i$O#&##&&#&O?$%=--_;+=o*?%??O%OOO?e?iioi!o*%O%?o?%%%$$$$$$$
?_``~o!???!!!!!ee*!OO#&##&##%??+.``^~_;+i*O$OOO$$OO%%?e*ie%%e%O?eo?e!$O$?!%$$
:` .+e!!eeeeeee**!!O#&#&&&#$?+.     `._:+=o*$OOO%%$%$$?*;o%?*!?*=e$$$###$$OOO
^ ^::i!e*o****e**!!$##&&&#O?-^       ``~_:_*$OOOOOOOO?!!;ie!io!*i?O##########
``_o;=*ooooo*****ee$#&&&&#?.`         ``^~-_%$OO#OOOOe*$?*o!io!=i!%OOOOO$$%$$
~_i*+oooooooo**o*ee$##&&##-.           ```.~*$$$OOOOO?o?$!o*i*o+o!%%?%%%????%
i;=i+iooooiioo**ee!$#&&&#e^             ``^^:$?$O$%OO$e!$?=+io==ee???????!!!?
?;_+=i=iooiioo**e!!O&&&&#:`              `^^^?OOO$?$OO%e?ei+i**oo*eeeee******
?*;;=iiiiiiioio**!!O&&&&?^ `       ```   ``^^:OO$O$OO$O$?i++io*==iooooooooooo
?*++=iiiiooioi**e!?O&&&&+```    ~=^-____~```^^*OOO##O$%$?o*!i=iiiiiiiiiiiii==
?o+=oiioooioo****!%#&&&O.`^`    -=_---_;+;^``^.%O####O$!!!?!i=i========++++++
!i=ioooiooo**e!e!?%#&&&*`^``` ``    `    .:.```;O####OO?!??!==i==++++;;;;;;;;
*=io*oooi*e!!???%$O#&&#-^.`````` ```..^^`` .^```e##OO$$%?!*o+===+;;:::::::___
oooeeee**!!%%%?%$O##&&?^.^`````^  `~.^^^`^.`````.$OOOO$**?!ooi=+;::_____-----
ee*eee!?%%%$$$%$OO#&&&+^.^`````^^`~~.^.^``.~^^```+OO#O$oe%*ioo++;::___:_-----
e*o**e?%%$%$OOO$$O#&&#~^.^^^^``^.~-....^``.~.~````?##O$e?%*+ii++;;::::;::____
eooo*%OOO#####OO$O#&&$^^.^^^``^^~-~....^^`^~~~^```_O#O$?%$$io=;;;;;;;;;;;;;::
*oo*!O#######O$%$O#&&e^..^^^`^^^.~.....^^`^.~~~^```*#O$%%O#$e;:;;;;:::_::____
*oe??%$%$%?%%%??%$##&i`..^^^^^^^.~.~...^``^.~~-.```.OO%%$O##!;_;+;:__-~--~~~~
*i*e*eeee!!!!e!!%%#O#+^^.....^^^.~.~~..^``^^.~-~^```+%$%?$##!;_;+;;:_~~-_-~~~
*ioe*ee*!!e!!e!!%$O?#+^^...~.^^^.~~~~.^```^^.~~-~```.%$?!$OO!;_;++;:_-~---~~~
o=ie*e**!e*ee*e%$##?#+`^..~~^^^^.~~...^```^^^.~--^```!%!%%OO?+:;++;;:_-~--~~~
o==**e*e!e*e?!oeO#O$&=``^.~~^^^.~~~...^` ``^^.~~~~```o%?%!?%?=::;;;;:-~~~~~~~
*i=*!e*eeeeee?%%O$$##=^`^.~.^^..~~~..``````^^^~~~~^``=$?%%%$$?i;++++;-~--~~~~
!oie!!e!!**eoo?%$####=_`^.~^....~~....~--_~.~....~~``~%*i!?!**i=====+:-::-~~~
!*ie!**!!***ooe%%#&&&i:.^^.^^..^.~~~__--:;;..~..~~~.``ee=***=iooiii==+++:-~~~
$?eeeoo!*ooi=i**io#&&e_~^^.^^..~::::__~-:::.-~-~+.~.^`iO$$$$???!!i=+++==;--~~
$%??*o*eo+oooi*o;i$O&$--^^.^^._::__:____::_.~--~*~..^^+####OO?%%?+;::;;;:----
!???!!!*oieo==*=;;+=e#:-.^^^.:___-_:__::__-~-.~~oi.^..;######$??e:______-----
??%?!e!eeee*ii*=;+=++*+_.^^.:__--------_-_.~-~--;?-..~+O######$%!:___--------
!!??ee?!ee*oii+;++i+;+i:-.._:-_--_-__--_--^~~.~-.**..-iO##O####$?:_______----
e!%?eee*o*o====+++=+;+i:;~.;_-_~~--------~^~-~.-.-!:~-*#OOO##O#$!+;;;:;;;:::_
ee??!eiii*oi==*=+;==+=o=;:~+_:_.~--~~~~~~..~~~.-~.i*.-*OOO#O##OOo=ii======+++
!**e!!oii*oi=o*+;;====oi;+-+::-~--~~~~~~~^.~~~.-~-~!:_eOO######Oe=iii=====+++
?!**ee*oo*ii=oo;:;==+=*o+;:=;;_~~~~~~~~~~^~~~~.-~_~o=_!#OO#####O$o======+++++
?*ii!eoooi===oi;;:+++=**o++=;;_.~~~~~....^.~~~.~~:_;o_?#OOOO###O%i+++++++++;;
!iii!oiooi==ioi===iiio*oi=+o=;_~~~~~~...^.~~~~.~~:_-o_%OOOO###OO%i;;;;;;;;;;;
!**e!ooo**iio*o+;+ii==iooo==o;:.~~~~~...^..~~~..~_:_=_$O#OOO##OO$e;;;::;;;:::
e**e*i=ioii=o!*i++===+ioi*i=o+:~~~~~~...`..~~~..~:;;+:OO#OOOOO##O%+::::::::__
ee*!oi=ioiii*!!o++==i=oooooi==;~~~~~~...^...~...-;;+;+$$O####O#OO$+::________
*oe*=iiooi=i*e*i==oi=+=ioi=ii+;~~~~~...^^...~~..-;+*;*OOO#######$%=::________
io!i+io**i=ie*i===ii==oe!ee?i=;-~~~....^^......._;e*;%OOO#####O#O$*;:;:______
=ie*ii=ii==ie*=++;=i=i**ee!?!i=_~~~....^........:;O*i$##OOO#O#O##O$+:;::_____
iiooii=i==io**=;;;====io*eeeeoi:-~~....^.....~..;=#!oOO##OOOO###O#Oi;;:__---_
**/

// Tribute to a friend I owe countless. Thanks, TN.