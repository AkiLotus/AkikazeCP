#include <iostream>
#include <vector>
using namespace std;

long long strtoll(string z) {
	long long result = 0, sign = 1, i = 0;
	if (z[0] == '-') {
		i = 1; sign = -1;
	}
	for (; i<z.size(); i++) {
		result *= 10;
		result += (z[i] - '0');
	}
	return result * sign;
}

int main() {
	int n;
	cin >> n;
	vector<bool> visited(n, false);
	int last = 0;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	int z = 0;
	while (!visited[last]) {
        int initial = last;
        z = last+1;
        int tmp = z-1;
        cout << a[initial];
        visited[initial] = true;
        for (; z<n; z++) {
            if (visited[z]) continue;
            if (a[z] > a[tmp]) {
                cout << " " << a[z];
                visited[z] = true;
                tmp = z;
            }
            else if (last == initial) last = z;
        }
        cout << endl;
	}
	return 0;
}
