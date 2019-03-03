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

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int M = rnd.next(900, 1000);
    cout << M << endl;

    for (int i=0; i<M; i++) {
    	string N = rnd.next("[0-9]{32,32}");
    	N[31]++; bool upper = false;
    	for (int i=31; i>=0; i--) {
    		if (N[i] > '9') {
    			N[i] -= 10;
    			if (i == 0) upper = true;
    			else N[i-1]++;
    		}
    	}
    	if (upper) N.insert(0, 1, '1');
    	while (N.size() > 1 && N[0] == '0') N.erase(0, 1);
        cout << N << endl;
    }

    return 0;
}