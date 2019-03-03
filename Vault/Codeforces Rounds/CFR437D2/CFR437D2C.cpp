// Template by proptit_4t41
// Applied for C++11/C++14
// Add -std=c++14 to your IDE.

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define MOD 1000000007LL
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
typedef pair<i64, i64> pii;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

// custom typedef here

// functions here
bool customSort(tiii a, tiii b) {
    i64 x1 = get<0>(a), y1 = get<1>(a), z1 = get<2>(a);
    i64 x2 = get<0>(b), y2 = get<1>(b), z2 = get<2>(b);
    if (abs(y1-z1) < abs(y2-z2)) return true;
    if (abs(y1-z1) == abs(y2-z2) && x1 > x2) return true;
    return false;
}

string problemName = "";
char* in = ".INP";
char* out = ".OUT";

int main() {
	//freopen("CFR437D2C.OUT", "r", stdin);
	//freopen(strcat(problemName,out), "w", stdout);
	//ios_base::sync_with_stdio(0);
	i64 n, s, ans = 0;
	cin >> n >> s;
	i64 type1 = 0, type2 = 0, even = 0;
	vector<tiii> prefer1, prefer2;
	for (i64 i=0; i<n; i++) {
        i64 x,y,z; cin >> x >> y >> z;
        ans += x*max(y,z);
        tiii tmp = make_tuple(x,y,z);
        if (y > z) {
            type1 += x;
            prefer1.pub(tmp);
        }
        else if (z > y) {
            type2 += x;
            prefer2.pub(tmp);
        }
        else even += x;
	}
	//cout << "Inputting caused RE?\n";
	//cout << type1 << " " << type2 << endl;
	type1 %= s; type2 %= s; even %= s;
	i64 loss1 = 0, loss2 = 0;
	//cout << "Calculations caused RE?\n";
	sort(prefer1.begin(), prefer1.end(), customSort);
	sort(prefer2.begin(), prefer2.end(), customSort);
	//cout << "Sorting caused RE?\n";
	if (type1 + type2 > s || type1 + type2 + even > s) cout << ans;
	else if (type1 + even <= s || type2 + even <= s) {
        for (i64 i=0; i<prefer1.size(); i++) {
            if (type1 == 0) break;
            i64 x = get<0>(prefer1[i]), y = get<1>(prefer1[i]), z = get<2>(prefer1[i]);
            if (x >= type1) {
                loss1 += (y-z)*type1; type1 = 0;
                break;
            }
            else {
                type1 -= x; loss1 += (y-z)*x;
            }
        }
        for (i64 i=0; i<prefer2.size(); i++) {
            if (type2 == 0) break;
            i64 x = get<0>(prefer2[i]), y = get<1>(prefer2[i]), z = get<2>(prefer2[i]);
            if (x >= type2) {
                loss2 += (z-y)*type2; type2 = 0;
                break;
            }
            else {
                type2 -= x; loss2 += (z-y)*x;
            }
        }
        //cout << "Analyzing caused RE?\n";
        //cout << ans << endl;
        //cout << loss1 << " " << loss2 << endl;
        ans -= min(loss1, loss2);
	}
	else {
        i64 tmp1 = type1 - (s - even), tmp2 = type2;
        i64 preans = 0;
        for (i64 i=0; i<prefer1.size(); i++) {
            if (tmp1 == 0) break;
            i64 x = get<0>(prefer1[i]), y = get<1>(prefer1[i]), z = get<2>(prefer1[i]);
            if (x >= tmp1) {
                loss1 += (y-z)*tmp1; tmp1 = 0;
                break;
            }
            else {
                tmp1 -= x; loss1 += (y-z)*x;
            }
        }
        for (i64 i=0; i<prefer2.size(); i++) {
            if (tmp2 == 0) break;
            i64 x = get<0>(prefer2[i]), y = get<1>(prefer2[i]), z = get<2>(prefer2[i]);
            if (x >= tmp2) {
                loss2 += (z-y)*tmp2; tmp2 = 0;
                break;
            }
            else {
                tmp2 -= x; loss2 += (z-y)*x;
            }
        }
        preans = min(loss1, loss2);
        tmp1 = type1; tmp2 = type2 - (s - even);
        loss1 = 0; loss2 = 0;
        for (i64 i=0; i<prefer1.size(); i++) {
            if (tmp1 == 0) break;
            i64 x = get<0>(prefer1[i]), y = get<1>(prefer1[i]), z = get<2>(prefer1[i]);
            if (x >= tmp1) {
                loss1 += (y-z)*tmp1; tmp1 = 0;
                break;
            }
            else {
                tmp1 -= x; loss1 += (y-z)*x;
            }
        }
        for (i64 i=0; i<prefer2.size(); i++) {
            if (tmp2 == 0) break;
            i64 x = get<0>(prefer2[i]), y = get<1>(prefer2[i]), z = get<2>(prefer2[i]);
            if (x >= tmp2) {
                loss2 += (z-y)*tmp2; tmp2 = 0;
                break;
            }
            else {
                tmp2 -= x; loss2 += (z-y)*x;
            }
        }
        preans = min(preans, min(loss1, loss2));
        ans -= preans;
	}
	cout << ans;
	return 0;
}
