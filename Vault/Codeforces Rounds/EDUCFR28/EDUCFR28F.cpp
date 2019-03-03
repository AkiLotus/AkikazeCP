#include <iostream>
using namespace std;

long long last[1000007];

int main() {
	long long n;
	cin >> n;
	long long sum = -n;
	for (int i=n; i>0; i--) sum += 2 * i * (n + 1 - i);
	long long a[n+1];
	for (long long i=1; i<=n; i++) {
        cin >> a[i];
        if (last[a[i]] == 0) last[a[i]] = i;
        else {
            sum -= (i - last[a[i]]) * 2;
            last[a[i]] = i;
        }
	}
	float answer = (float)sum / (n * n);
	cout << answer;
	return 0;
}
