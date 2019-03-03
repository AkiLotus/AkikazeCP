#include <iostream>
#include <algorithm>
using namespace std;

struct pokemon {
	string pokeName;
	int pokeUpgrade, pokeAvailable;
	int pokeID, upgradedCount;
};

bool pokeSort (pokemon a, pokemon b) {
	if (a.upgradedCount > b.upgradedCount) return true;
	if (a.upgradedCount == b.upgradedCount && a.pokeID < b.pokeID) return true;
	return false;
}

int main() {
	int n, upgraded = 0;
	cin >> n;
	pokemon a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i].pokeName >> a[i].pokeUpgrade >> a[i].pokeAvailable;
		a[i].pokeID = i;
		if (a[i].pokeAvailable < a[i].pokeUpgrade) a[i].upgradedCount = 0;
		else {
			a[i].upgradedCount = a[i].pokeAvailable / (a[i].pokeUpgrade - 2);
			upgraded += a[i].upgradedCount;
		}
	}
	sort(a, a+n, pokeSort);
	cout << upgraded << endl << a[0].pokeName;
	return 0;
}
