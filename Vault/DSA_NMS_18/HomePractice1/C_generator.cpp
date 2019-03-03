#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 1000);
    cout << T << endl;
    for (int i=1; i<=T; i++) {
    	string s = rnd.next("[0-9]{1,80}");
        cout << i << " " << s << endl;
    }
    return 0;
}
