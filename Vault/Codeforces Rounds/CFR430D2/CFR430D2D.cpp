#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool exist[333333];
	for (int i=0; i<333333; i++) exist[i] = false;
	for (int i=0; i<n; i++) {
        int z;
        cin >> z;
        exist[z] = true;
	}
	int z = 0;
	while (m-- > 0) {
        int x;
        cin >> x;
        z = z ^ x;
        int output = 0;
        while (output < 333333) {
            if (!exist[output ^ z]) {
                cout << (output) << endl;
                break;
            }
            output++;
        }
	}
	return 0;
}
