#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 20);
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	vector<int> a(5);
        for (int j=0; j<5; j++) a[j] = rnd.next(1, 100);
        for (int j=0; j<5; j++) {
            cout << a[j];
            if (j == 4) cout << endl; else cout << " ";
        }
    }
    return 0;
}
