#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 9) + 1;
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	long long z = rnd.next(1LL, 1000000000000000LL);
        int a = 0;
        for (long long i=1; i<=sqrt(z); i++) {
            if (z % i == 0) {
                a++; if (i != z/i) a++;
            }
        }
        cout << a << endl;
    }
    cout << "1\n";
    return 0;
}
