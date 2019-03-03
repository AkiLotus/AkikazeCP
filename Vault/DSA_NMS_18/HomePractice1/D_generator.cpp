#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int N = rnd.next(1, 10), K = rnd.next(0, 100000);
    cout << N << " " << K << endl;
    for (int i=1; i<=N; i++) {
    	for (int j=1; j<=N; j++) {
    		cout << (rnd.next(0, 1000));
    		if (j == N) cout << "\n"; else cout << " ";
    	}
    }
    return 0;
}
