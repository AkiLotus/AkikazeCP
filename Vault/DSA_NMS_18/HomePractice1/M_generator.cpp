#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 50);
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	cout << (rnd.next(1, 100000)) << endl;
    }
    return 0;
}
