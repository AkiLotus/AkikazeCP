#include <iostream>
using namespace std;

int main() {
	int N;
	int classes[16];
	for (int i=0; i<16; i++) classes[i] = 0;
	cin >> N;
	while (N-- > 0) {
        string name, group;
        cin >> name >> group;
        if (group.size() == 4) {
            classes[group[3] - '0' + 9]++;
        }
        else {
            if (group.find("AT") != -1) classes[group[2] - '0' + 11]++;
            else classes[group[2]-'0'-1]++;
        }
	}
	for (int i=0; i<12; i++) cout << "CN" << i+1 << " " << classes[i] << endl;
	for (int i=12; i<16; i++) cout << "AT" << i-11 << " " << classes[i] << endl;
	return 0;
}
