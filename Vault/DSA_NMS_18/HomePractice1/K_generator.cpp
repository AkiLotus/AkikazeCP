#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 10);
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	int N = rnd.next(2, 20);
    	int M = rnd.next(1, min(20, N*(N-1)));
    	cout << N << " " << M << endl;
    	vector<pair<int, int>> a;
        for (int q=0; q<N; q++) {
            for (int r=0; r<N; r++) {
                if (q == r) continue;
                a.push_back(make_pair(q+1, r+1));
            }
        }
    	shuffle(a.begin(), a.end());
    	for (int i=0; i<M; i++) {
    		cout << a[i].first << " " << a[i].second << endl;
    	}
    }
    return 0;
}
