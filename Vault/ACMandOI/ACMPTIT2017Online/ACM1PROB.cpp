#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct judge {
	judge (): count(-1), first(-1), second(-1), third(-1) {}
	int count;
	int first, second, third;
};

struct contestants {
	contestants (): ID(-1), point(0), first(0), second(0) {}
	contestants (int ID_): ID(ID_), point(0), first(0), second(0) {}
	int ID;
	int point;
	int first, second;
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
		vector<contestants> out;
		vector<int> contID;
		for (int i=0; i<n; i++) {
			cin >> inp[i].count >> inp[i].first;
			int tmp = find(contID.begin(), contID.end(), inp[i].first) - contID.begin();
			if (tmp == contID.size()) {
				contestants ctmp(inp[i].first);
				out.push_back(ctmp);
				contID.push_back(inp[i].first);
			}
			out[tmp].point += 3;
			out[tmp].first++;
			if (inp[i].count > 1) {
				cin >> inp[i].second;
				int tmp = find(contID.begin(), contID.end(), inp[i].second) - contID.begin();
				if (tmp == contID.size()) {
					contestants ctmp(inp[i].second);
					out.push_back(ctmp);
					contID.push_back(inp[i].second);
				}
				out[tmp].point += 2;
				out[tmp].second++;
			}
			if (inp[i].count == 3) {
				cin >> inp[i].third;
				int tmp = find(contID.begin(), contID.end(), inp[i].third) - contID.begin();
				if (tmp == contID.size()) {
					contestants ctmp(inp[i].third);
					out.push_back(ctmp);
					contID.push_back(inp[i].third);
				}
				out[tmp].point++;
			}
		}
		sort(out.begin(), out.end(), concmp);
		for (int i=0; i<out.size(); i++) {
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
