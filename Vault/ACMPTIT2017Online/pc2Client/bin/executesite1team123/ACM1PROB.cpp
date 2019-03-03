#include <iostream>
#include <algorithm>
using namespace std;

struct judge {
	int count = -1;
	int first = -1, second = -1, third = -1;
};

struct contestants {
	int ID = -1;
	int point = 0;
	int first = 0, second = 0;
};

int concmp (contestants a, contestants b) {
	if (a.point > b.point) return 1;
	if (a.point == b.point && a.first > b.first) return 1;
	if (a.point == b.point && a.first == b.first && a.second > b.second) return 1;
	if (a.point == b.point && a.first == b.first && a.second ==  b.second && a.ID < b.ID) return 1;
	return 0;
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		judge inp[n];
		contestants out[1048576];
		int maxcon = -1;
		for (int i=0; i<n; i++) {
			cin >> inp[i].count >> inp[i].first;
			out[inp[i].first].ID = inp[i].first;
			maxcon = max(maxcon, inp[i].first);
			out[inp[i].first].point += 3;
			out[inp[i].first].first++;
			if (inp[i].count > 1) {
				cin >> inp[i].second;
				out[inp[i].second].ID = inp[i].second;
				maxcon = max(maxcon, inp[i].second);
				out[inp[i].second].point += 2;
				out[inp[i].second].second++;
			}
			if (inp[i].count == 3) {
				cin >> inp[i].third;
				out[inp[i].third].ID = inp[i].third;
				maxcon = max(maxcon, inp[i].third);
				out[inp[i].third].point++;
			}
		}
		sort(out, out+maxcon+1, concmp);
		for (int i=0; i<=maxcon; i++) {
			if (i == 0) cout << out[i].ID;
			else {
				if (out[i].point == out[i-1].point && out[i].first == out[i-1].first && out[i].second == out[i-1].second) {
					cout << " " << out[i].ID;
				}
				else break;
			}
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}