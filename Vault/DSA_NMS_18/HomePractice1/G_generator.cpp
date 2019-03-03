#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 20);
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	for (int x=0; x<8; x++) {
    		for (int y=0; y<8; y++) {
    			cout << (rnd.next(0, 100));
    			if (y == 7) cout << endl; else cout << " ";
    		}
    	}
    }
    return 0;
}
