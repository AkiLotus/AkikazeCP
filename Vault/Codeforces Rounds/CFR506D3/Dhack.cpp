#include<iostream>
using namespace std;

int main() {
	srand(18394);
	cout << "200000 999999929\n";
	for (int i=0; i<200000; i++) {
		int a = (rand() % 31622) * (rand() % 31622);
		if (a == 0) a++; cout << a;
		if (i == 199999) cout << "\n"; else cout << " ";
	}
}