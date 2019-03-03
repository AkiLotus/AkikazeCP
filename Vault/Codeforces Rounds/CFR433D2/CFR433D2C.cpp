#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data {
    long long x, y;
};

bool dataSort(data a, data b) {
    if (a.x > b.x) return true;
    if (a.x == b.x && a.y < b.y) return true;
    return false;
}

int main() {
    vector<long long> avail;
	long long n, k;
	cin >> n >> k;
	for (long long i=k+1; i<=n+k; i++) avail.push_back(i);
	data c[n];
	long long schedule[n];
	for (long long i=0; i<n; i++) {
        cin >> c[i].x;
        c[i].y = i+1;
	}
	sort(c, c+n, dataSort);
	long long answer = 0;
	for (long long i=0; i<n; i++) {
        long long tmp = lower_bound(avail.begin(), avail.end(), c[i].y) - avail.begin();
        long long z = avail[tmp];
        avail.erase(avail.begin()+tmp);
        answer += (z - c[i].y) * c[i].x;
        schedule[c[i].y-1] = z;
	}
	cout << answer << endl;
	for (long long i=0; i<n; i++) cout << schedule[i] << " ";
	return 0;
}
