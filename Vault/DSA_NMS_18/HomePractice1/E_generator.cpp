#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 20);
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	int N = rnd.next(1, 16);
    	int K = rnd.next(1, N);
    	cout << N << " " << K << endl;
    }
    return 0;
}
