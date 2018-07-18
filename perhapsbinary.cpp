#include <iostream>
using namespace std;

int main() {
	// giả định f(x) = x+1
	long long y, a, b;
	cin >> y >> a >> b;
	// cái hàm nó đồng biến rõ rồi nên t làm hơi tắt 1 tí
	while (a != b) {
        long long mid = (a + b) / 2;
        if (mid+1 == y) {
            a = mid; b = mid; break;
        }
        if (mid+1 > y) b = mid;
        else a = mid;
	}
	if (a + 1 == y) cout << a;
	else cout << "pt vo nghiem";
	return 0;
}
