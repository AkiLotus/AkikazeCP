#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 20);
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	int N = rnd.next(2, 39);
    	int K = rnd.next(1, N-1);
    	cout << N << " " << K << endl;
    	vector<int> a(N); for (int q=0; q<N; q++) a[q] = q+1;
    	shuffle(a.begin(), a.end());
    	for (int i=0; i<K; i++) {
    		cout << a[i];
    		if (i < K-1) cout << " "; else cout << endl;
    	}
    }
    return 0;
}
