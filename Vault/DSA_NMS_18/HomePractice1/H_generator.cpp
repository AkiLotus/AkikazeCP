#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 100);
    for (int i=0; i<T; i++) {
        int n = rnd.next(1, 20);
        int k = rnd.next(1, 10);
        int s = rnd.next(1, 155);
        cout << n << " " << k << " " << s << endl;
    }
    cout << "0 0 0\n";
    return 0;
}
