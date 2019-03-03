#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
 
int main() {
	long long n;
	cin >> n;
	long long val[n];
	long long total = 0;
	long long count = 0;
	for (int i=0; i<n; i++) {
		cin >> val[i];
		total += val[i];
		count++;
	}
	sort(val, val+n);
	double max = 0.0, aout, bout;
	long long sum = 0;
	for (long long i=0; i<n; i++) {
		sum += val[n-1-i];
		double a = (double)100 * (i + 1) / n;
		double b = (double)100 * sum / total;
		double cmp = b - a;
		if (cmp > max) {
			max = cmp;
			aout = a;
			bout = b;
		}
	}
	cout << fixed << setprecision(1) << aout << " " << bout;
	return 0;
}
