#pragma comment(linker, "/stack:252457298")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

int a = 0, b = 0;

void Input() {
	
}

void Solve() {
	int relation = -4, skipped = false;
	vector<int> notDetermined;
	for (int i=29; i>=0; i--) {
		if (relation == 0) {
			cout << "? " << (a ^ (1 << i)) << " " << b << endl; fflush(stdout);
			int tmprela1; cin >> tmprela1; while (tmprela1 == -2) cout << "z";
			if (tmprela1 == -1) {a ^= (1 << i); b ^= (1 << i);}
			continue;
		}
		if (!skipped) {
			cout << "? " << a << " " << b << endl;
			fflush(stdout); cin >> relation;
		}
		else skipped = false;
		if (relation == 0) {
			cout << "? " << (a ^ (1 << i)) << " " << b << endl; fflush(stdout);
			int tmprela1; cin >> tmprela1; while (tmprela1 == -2) cout << "z";
			if (tmprela1 == -1) {a ^= (1 << i); b ^= (1 << i);}
			continue;
		}
		cout << "? " << (a ^ (1 << i)) << " " << (b ^ (1 << i)) << endl; fflush(stdout);
		int tmprela; cin >> tmprela; while (tmprela == -2) cout << "z";
		if (tmprela == relation) {notDetermined.push_back(i); skipped = true;}
		else if (tmprela < relation) a ^= (1 << i);
		else b ^= (1 << i);
	}
	for (auto i: notDetermined) {
		cout << "? " << (a ^ (1 << i)) << " " << b << endl; fflush(stdout);
		int tmprela1; cin >> tmprela1; while (tmprela1 == -2) cout << "z";
		if (tmprela1 == -1) {a ^= (1 << i); b ^= (1 << i);}
		continue;
	}
	cout << "! " << a << " " << b << endl; fflush(stdout);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/**********************************************\
 *  Ngoc-Mai Ngo, #Team4T's Deputy Leader     *
 *  #Team4T Secondary Flagship - Destruction  *
\**********************************************/
