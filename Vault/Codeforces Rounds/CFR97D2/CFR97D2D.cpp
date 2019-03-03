#include <iostream>
#include <algorithm>
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
	pair<int, int> coor[8];
	int a[4], b[4], c[4];
	for (int i=0; i<8; i++) cin >> coor[i].first >> coor[i].second;
	for (a[0] = 0; a[0] < 8; a[0]++) {
        for (a[1] = 0; a[1] < 8; a[1]++) {
            if (a[1] == a[0]) continue;
            for (a[2] = 0; a[2] < 8; a[2]++) {
                if (a[2] == a[1] || a[2] == a[0]) continue;
                for (a[3] = 0; a[3] < 8; a[3]++) {
                    if (a[3] == a[2] || a[3] == a[1] || a[3] == a[0]) continue;
                    int cc = 0;
                    for (int i=0; i<8; i++) {
                        if (i != a[0] && i != a[1] && i != a[2] && i != a[3]) c[cc++] = i;
                    }
                    for (int i=0; i<4; i++) {
                        for (int j=0; j<4; j++) {
                            if (j == i) continue;
                            for (int k=0; k<4; k++) {
                                if (k == i || k == j) continue;
                                for (int l=0; l<4; l++) {
                                    if (l == i || l == j || l == k) continue;
                                    b[0] = c[i]; b[1] = c[j]; b[2] = c[k]; b[3] = c[l];
                                    int sa[6];
                                    sa[0] = (coor[a[1]].first - coor[a[0]].first) * (coor[a[1]].first - coor[a[0]].first) + (coor[a[1]].second - coor[a[0]].second) * (coor[a[1]].second - coor[a[0]].second);
                                    sa[1] = (coor[a[1]].first - coor[a[2]].first) * (coor[a[1]].first - coor[a[2]].first) + (coor[a[1]].second - coor[a[2]].second) * (coor[a[1]].second - coor[a[2]].second);
                                    sa[2] = (coor[a[1]].first - coor[a[3]].first) * (coor[a[1]].first - coor[a[3]].first) + (coor[a[1]].second - coor[a[3]].second) * (coor[a[1]].second - coor[a[3]].second);
                                    sa[3] = (coor[a[2]].first - coor[a[0]].first) * (coor[a[2]].first - coor[a[0]].first) + (coor[a[2]].second - coor[a[0]].second) * (coor[a[2]].second - coor[a[0]].second);
                                    sa[4] = (coor[a[2]].first - coor[a[3]].first) * (coor[a[2]].first - coor[a[3]].first) + (coor[a[2]].second - coor[a[3]].second) * (coor[a[2]].second - coor[a[3]].second);
                                    sa[5] = (coor[a[3]].first - coor[a[0]].first) * (coor[a[3]].first - coor[a[0]].first) + (coor[a[3]].second - coor[a[0]].second) * (coor[a[3]].second - coor[a[0]].second);
                                    int sb[6];
                                    sb[0] = (coor[b[1]].first - coor[b[0]].first) * (coor[b[1]].first - coor[b[0]].first) + (coor[b[1]].second - coor[b[0]].second) * (coor[b[1]].second - coor[b[0]].second);
                                    sb[1] = (coor[b[1]].first - coor[b[2]].first) * (coor[b[1]].first - coor[b[2]].first) + (coor[b[1]].second - coor[b[2]].second) * (coor[b[1]].second - coor[b[2]].second);
                                    sb[2] = (coor[b[1]].first - coor[b[3]].first) * (coor[b[1]].first - coor[b[3]].first) + (coor[b[1]].second - coor[b[3]].second) * (coor[b[1]].second - coor[b[3]].second);
                                    sb[3] = (coor[b[2]].first - coor[b[0]].first) * (coor[b[2]].first - coor[b[0]].first) + (coor[b[2]].second - coor[b[0]].second) * (coor[b[2]].second - coor[b[0]].second);
                                    sb[4] = (coor[b[2]].first - coor[b[3]].first) * (coor[b[2]].first - coor[b[3]].first) + (coor[b[2]].second - coor[b[3]].second) * (coor[b[2]].second - coor[b[3]].second);
                                    sb[5] = (coor[b[3]].first - coor[b[0]].first) * (coor[b[3]].first - coor[b[0]].first) + (coor[b[3]].second - coor[b[0]].second) * (coor[b[3]].second - coor[b[0]].second);
                                    if (sa[0] == sa[1] && sa[1] == sa[4] && sa[4] == sa[5] && sa[2] == sa[3] && sa[0] * 2 == sa[2] && sb[0] == sb[4] && sb[1] == sb[5] && sb[2] == sb[3] && sb[0] + sb[1] == sb[2] && sa[0] != 0 && (sb[0] != 0 || sb[1] != 0)) {
                                        cout << "YES\n";
                                        for (int i=0; i<4; i++) cout << a[i]+1 << " "; cout << endl;
                                        for (int i=0; i<4; i++) cout << b[i]+1 << " ";
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
	}
    cout << "NO";
	return 0;
}
