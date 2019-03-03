#include "testlib.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
#define fi first
#define se second

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int N = rnd.next(90000, 100000), T = rnd.next(90000, 100000);
    cout << N << endl;

    queue<ppp> Q; Q.push(make_pair(make_pair(1, 1), make_pair(100000, 100000)));
    while (Q.size() <= 2*N) {
    	ppp z = Q.front(); Q.pop(); int x = 0, y = 0;
    	if (z.se.fi - z.fi.fi == 1 && z.se.se - z.fi.se == 1) {Q.push(z); continue;}
    	do {
    		x = rnd.next(z.fi.fi + 1, z.se.fi);
    		y = rnd.next(z.fi.se + 1, z.se.se);
    	} while (z.second == make_pair(x, y));
        if (y == z.se.se) {
            Q.push(make_pair(make_pair(z.fi.fi, z.fi.se), make_pair(x, y)));
            Q.push(make_pair(make_pair(x, z.fi.se), make_pair(z.se.fi, z.se.se)));
        }
        else if (x == z.se.fi) {
            Q.push(make_pair(make_pair(z.fi.fi, z.fi.se), make_pair(x, y)));
            Q.push(make_pair(make_pair(z.fi.fi, y), make_pair(z.se.fi, z.se.se)));
        }
    	else {
    		Q.push(make_pair(make_pair(z.fi.fi, z.fi.se), make_pair(x, y)));
    		Q.push(make_pair(make_pair(x, z.fi.se), make_pair(z.se.fi, y)));
    		Q.push(make_pair(make_pair(z.fi.fi, y), make_pair(x, z.se.se)));
    		Q.push(make_pair(make_pair(x, y), make_pair(z.se.fi, z.se.se)));
    	}
    }

    vector<ppp> partition; while (!Q.empty()) {partition.push_back(Q.front()); Q.pop();}
    shuffle(partition.begin(), partition.end());
    for (int i=0; i<N; i++) {
    	ppp z = partition[i];
    	int x1 = rnd.next(z.fi.fi, z.se.fi-1), y1 = rnd.next(z.fi.se, z.se.se-1);
    	int x2 = rnd.next(x1+1, z.se.fi), y2 = rnd.next(y1+1, z.se.se);
    	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }

    cout << T << endl;
    for (int i=0; i<T; i++) {
    	int x = rnd.next(0, 200000) - 100000;
    	int d = rnd.next(1, 1);
    	cout << x << " " << d << endl;
    }

    return 0;
}