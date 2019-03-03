#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = rnd.next(1, 50);
    cout << T << endl;
    for (int i=0; i<T; i++) {
    	int n = (rnd.next(1, 100000));
    	cout << n << endl;
    	for (int x=0; x<n; x++) {
    		int a = rnd.next(0, 999999);
    		int b = rnd.next(a+1, 1000000);
    		cout << a << " " << b << endl;
    	}
    }
    return 0;
}
