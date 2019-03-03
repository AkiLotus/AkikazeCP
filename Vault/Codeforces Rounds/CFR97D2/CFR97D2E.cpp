#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string cards; cin >> cards;
	int cc0 = 0, cc1 = 0, ccq = 0, last0 = -1, last1 = -1;
	int n = cards.size();
	for (int i=0; i<n; i++) {
        if (cards[i] == '0') {
            cc0++; last0 = i;
        }
        else if (cards[i] == '1') {
            cc1++; last1 = i;
        }
        else if (cards[i] == '?') ccq++;
	}
	if (ccq == 0) {
        if (cc1 == cc0 || cc1 == cc0+1) {
            if (last1 < last0) cout << "10";
            else cout << "01";
        }
        else if (cc1 > cc0+1) cout << "11";
        else cout << "00";
	}
	else {
        if (cc1 < cc0 + ccq) cout << "00\n";
        if (cards[n-1] == '?') {
            ccq--; cc1++;
        }
        int x = (cc0 + ccq - cc1 + (cc1 + cc0 + ccq) % 2) / 2;
        if (cards[n-1] != '0' && x >= 0 && x <= ccq) cout << "01\n";
        if (cards[n-1] == '?') {
            cc0++; cc1--;
        }
        int y = (cc0 + ccq - cc1 + (cc1 + cc0 + ccq) % 2) / 2;
        if (cards[n-1] != '1' && y >= 0 && y <= ccq) cout << "10\n";
        if (cards[n-1] == '?') {
            ccq++; cc0--;
        }
        if (cc1 + ccq > cc0 + 1) cout << "11";
	}
	return 0;
}
