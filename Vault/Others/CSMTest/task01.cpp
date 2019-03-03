#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B;
	cin >> C >> D;
	int t0 = A*B-C*D;
	int t1 = A*C-B*D;
	int t0a = abs(t0);
	int t1a = abs(t1);
	if (t0a > t1a) {
		if (t0 > 0) {
			cout << "0";
		}
		else cout << "2";
	}
	else {
		if (t1 > 0) {
			cout << "1";
		}
		else cout << "3";
	}
	return 0;
}
