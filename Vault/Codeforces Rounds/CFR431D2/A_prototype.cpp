#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	if (a[0] % 2 == 0 || a[n-1] % 2 == 0) {
        cout << "No";
        return 0;
	}
	if (n % 2 == 1) cout << "Yes";
	else {
        for (int i=2; i<n-2; i+=2) {
            if (a[i] % 2 != 0 && a[i+1] % 2 != 0) {
                cout << "Yes";
                return 0;
            }
        }
        cout << "No";
	}
	return 0;
}
