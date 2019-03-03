#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int N = rnd.next(1, 15);
    cout << N << endl;
    	for (int x=0; x<N; x++) {
    		for (int y=0; y<N; y++) {
    			cout << (rnd.next(0, 100));
    			if (y == N-1) cout << endl; else cout << " ";
    		}
    	}
    return 0;
}
