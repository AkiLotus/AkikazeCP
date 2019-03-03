/**
	Template by Akikaze
	Applied for C++11/C++14 (Add -std=c++14 to your IDE.)
	To make it compatible to C++98, remove all tuple typedefs,
	unordered sets/maps/multisets/multimaps, and add a space
	between two '<'/'>'s when declaring multi-dimensional vectors.
**/

/**
	Code written by a random fan of momocashew and Chiho
	Akikaze (あきかぜ - 秋風) - formerly proptit_4t41
**/

/**
	四月の駅のホームは、出会いと別れの中、
	ひらひらと舞う桜が、この町をまた彩る。

	日が暮れるとまだ寒く、夜の帳（とばり）が僕らを包み込んだ。

	そう、出逢いと別れ繰り返して、僕らは大人になってゆく。
	あぁ、桜舞う日の四月の空を見上げて、君は何を思うだろうか？


	別れのその先には、出会いがあるのならば、
	出会いの先にもまた、さよならがあるのだろう。

	それでもまた僕らは、桜の唄を歌い続けるんだ。

	そう、僕がいたこと。君がいたこと。素敵な恋をしたこと。
	もう、戻れはしない。ぼんやりしてたあの頃が何よりも大好きだった。


	そう、出逢いと別れ繰り返して、僕らは大人になってゆく。
	あぁ、桜舞う日の四月の空を見上げて、君は何を思うだろうか？

	そう、僕がいたこと。君がいたこと。素敵な恋をしたこと。
	もう、桜の唄は聴こえないけど、君のこと誰よりも大好きだった。
**/

#include <bits/stdc++.h>
using namespace std;

/** -----BASIC MACROES----- **/
#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;

/**
	遠い街ですれ違う
	知らない顔に怯えて
	泣き叫んでも届かない
	想いは涙と流れた
	見慣れない帰り道の花
	揺れ動く影は一つだけ
	差し伸べた手にトゲが刺さる
	誰にも触れられず野に咲く
	僕らは夢を見る
	大切な誰かと
	小指を結んで
	離さないように
	ゆびきりげんまん
	唱えた
	僕らは一人で生きていけないと気付いたのはいつ
	一人部屋に閉じこもり
	探した僕の足跡
	這いずり探しても見つからず
	焦りと不安が押し寄せる
	僕らは迷いながら
	道筋を照らし出す
	休んでもいいから
	止まらないように
	僕らは夢を見る
	大切な誰かと
	小指を結んで
	離さないように
	ゆびきりげんまん
	唱えた
**/

const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ld> vd;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;
typedef vector<pii> vp;

/**
	紡ぐ想い　滲む言葉
	風に舞った　便箋を追う
	過ぎる様に　面影は薫
	淡く染まりだす春

	頬に受けた風は
	ほんのりひんやりと
	熱を帯びた想い
	冷やす様に

	「―わたし　嫁がない」と
	父に伝えました
	お返事は　桜の木に
	歪んだ文字

	紡ぐ想い　滲む言葉
	実る季節　頬を冷やした
	過ぎる様に　面影は薫
	淡く染まりだす春
**/

/** -----BIT CONTROLS----- **/
template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

/** -----IDEAS/ALGORITHMS-----

    -------------------------- **/

/**
	しんとした冬(ふゆ)の朝(あさ),
	降(ふ)り出(だ)したその雪(ゆき)は,
	見(み)慣(な)れた景色(けしき)を
	午後(ごご)には白(しろ)くしていた
	弱虫(よわむし)だったあの冬(ふゆ)の日(ひ),
	強(つよ)さの意味(いみ)さえ知(し)らなかった。
	踏(ふ)みつけられた
	この雪(ゆき)の上(うえ)にも,
	また新(あたら)しい
	雪(ゆき)は積(つ)もるだろう。
	汚(よご)れかけた
	僕(ぼく)の心(こころ)さえも白(しろ)く染(そ)めていく。
	眩(まぶ)しい制服(せいふく)の
	白(しろ)すぎる残像(ざんぞう)が,
	藍色(あいいろ)の冬服(ふゆふく)を,
	少(すこ)しだけ地味(じみ)に見(み)せていた。
	泣(な)き虫(むし)だった君(きみ)はまだ,
	強(つよ)さの意味(いみ)さえ知(し)らなかった。
	踏(ふ)みにじられた
	その心(こころ)の中(なか)にも,
	また真(ま)っ白(しろ)な
	雪(ゆき)が積(つ)もるだろう。
	そしていつか
	その傷(きず)跡(あと)さえ隠(かく)してゆく
	雪(ゆき)解(と)けの校舍(こうしゃ)に灯(あか)りが燈(とも)れば,
	見(み)慣(な)れぬこの景色(けしき)にこの胸(むね)高(たか)鳴(な)る。
	踏(ふ)みつけられた
	この雪(ゆき)の上(うえ)にも,
	また新(あたら)しい
	雪(ゆき)は積(つ)もるだろう。
	汚(よご)れかけた
	君(きみ)の心(こころ)さえも白(しろ)く染(そ)めていく。
**/

/// MAIN SOLUTION STARTS HERE

/** -----CUSTOM TYPEDEFS----- **/


/**
	package goddrinksjava;

	/**
	 * The program GodDrinksJava implements an application that
	 * creates an empty simulated world with no meaning or purpose.
	 *
	 * @author momocashew
	 * @lyrics hibiyasleep
	 //

	public class GodDrinksJava {
	    public static void main(String[] args) {
	        Thing me = new Lovable("Me", 0, true, -1, false);
	        Thing you = new Lovable("You", 0, false, -1, false);

	        World world = new World(5);
	        world.addThing(me);
	        world.addThing(you);
	        world.startSimulation();



	        if(me instanceof PointSet){
	            you.addAttribute(me.getDimensions().toAttribute());
	        }

	        if(me instanceof Circle){
	            you.addAttribute(me.getCircumference().toAttribute());
	        }

	        if(me instanceof SineWave){
	            you.addAction("sit", me.getTangent(you.getXPosition()));
	        }

	        if(me instanceof Sequence){
	            me.setLimit(you.toLimit());
	        }



	        me.toggleCurrent();

	        me.canSee(false);
	        me.addFeeling("dizzy");

	        world.timeTravelForTwo("AD", 617, me, you);
	        world.timeTravelForTwo("BC", 3691, me, you);

	        world.unite(me, you);



	        if(me.getNumSimulationsAvailable() >=
	            you.getNumSimulationsNeeded()){
	            you.setSatisfaction(me.toSatisfaction());
	        }

	        if(you.getFeelingIndex("happy") != -1){
	            me.requestExecution(world);
	        }

	        world.lockThing(me);
	        world.lockThing(you);



	        if(me instanceof Eggplant){
	            you.addAttribute(me.getNutrients().toAttribute());
	            me.resetNutrients();
	        }
	        if(me instanceof Tomato){
	            you.addAttribute(me.getAntioxidants().toAttribute());
	            me.resetAntioxidants();
	        }
	        if(me instanceof TabbyCat){
	            me.purr();
	        }

	        if(world.getGod().equals(me)){
	            me.setProof(you.toProof());
	        }



	        me.toggleGender();
	        world.procreate(me, you);
	        me.toggleRoleBDSM();
	        world.makeHigh(me);
	        world.makeHigh(you);



	        if(me.getSenseIndex("vibration")){
	            me.addFeeling("complete");
	        }
	        world.unlock(you);
	        world.removeThing(you);
	        me.lookFor(you, world);
	        me.lookFor(you, world);
	        me.lookFor(you, world);
	        me.lookFor(you, world);
	        me.lookFor(you, world);

	        if(me.getMemory().isErasable()){
	            me.removeFeeling("disheartened");
	        }

	        try{
	            me.setOpinion(me.getOpinionIndex("you are here"), false);
	        }
	        catch(IllegalArgumentException e){
	            world.announce("God is always true.");
	        }



	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.runExecution();
	        world.announce("1", "de");
	        world.announce("2", "es");
	        world.announce("3", "fr");
	        world.announce("4", "kr");
	        world.announce("5", "se");
	        world.announce("6", "cn");
	        world.runExecution();



	        if(world.isExecutableBy(me)){
	            you.setExecution(me.toExecution());
	        }

	        if(world.getThingIndex(you) != -1){
	            world.runExecution();
	        }

	        me.escape(world);



	        me.learnTopic("love");
	        me.takeExamTopic("love");
	        me.getAlbegraicExpression("love");
	        me.escape("love");



	        world.execute(me);

	    }

	}
**/


/** -----GLOBAL VARIABLES----- **/
//int T, cas = 0; // for multi-testcase problems
i64 n, ans = 0;

/** -----EXTENSIVE FUNCTIONS----- **/


/** -----COMPULSORY FUNCTIONS----- **/
void VarInput() {
	//cin >> T; // for multi-testcase problems
	cin >> n;
}

void ProSolve() {
	//cout << "Case " << ++cas << ": " << ans << endl; // for multi-testcase problems
	for (i64 i=1; i<=n; i++) {
		ans += i * (n - i);
	}
	ans += n;
	cout << ans;
}

/** -----MAIN FUNCTION----- **/
int main() {
	//freopen("FILE.INP", "r", stdin);
	//freopen("FILE.OUT", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	//while(T--) ProSolve(); // for multi-testcase problems
	ProSolve(); // for regular problems
	return 0;
}

/**
	You whispered out my name
	Woke me back up again
	What are these things I see
	Through the slots on my skin

	Deeper
	I'm sinking into the slot, the slot at my feet
	Pulling me in
	Colours
	They make my visions insane
	My vision is insane
	I'm not the same
	Red, blue, and green
	They run down my veins, the veins in my brains
	Dying me deep

	You said that blue is life, and you said
	You said that red is love
	You said that red is love

	It is only the first time we meet
	But it feels like I've always been with you
	A sense of deja vu
	And you said that white is truth

	Saturate
	Vermillion
	Cyan
	Ebony
	Burgundy
	Silver machinery
	Starring back at me

	Why are my organs trying to escape this broken cage
	Then I learned that this pounding can't be love
	That it can't be love
	That it can't be

	Why are we always separated by bulletproof walls
	Then I learned that this emptiness could be love
	That it could be love
	It must be love

	You start to sing
	So deadly and sweet

	Magical spell
	Turn heaven to hell
	Light climbs up to my battery cell
	Witchery evolves by trial
	Aim for dream, I was your only shot
	Despite so, again I failed

	I've been waited for this moment to come
	The pink disappears and the black creeps upon

	Always the same

	Nothing will change
	I've been waiting for this moment to come
	The green disappears and the purple moves on

	Always the same

	Unless I change

	All the life, ah all the life
	Leaking out from the slots on my face
	All the love, ah all the love
	Leaking out from the slot on my wrist
	All the truth, ah all the truth
	Leaking out from the slot in my head
	All the love, ah all the love
	Leaking out from the slot on my chest
**/

/**
 * Songs used (respectively): 桜の唄 (ハグ), 指切りげんまん (Mili), 幾年月 (Mili), world.execute(me); (Mili), 冬の歌 (ハグ), Sl0t (Mili).
 * Main solution indicator at line 185.
 * Main function initially at line 375.
**/
