#include <iostream>
using namespace std;

int main() {
    //freopen("data.in", r, stdin);
    //freopen("ketqua.out", w, stdout);
	int t;
	cin >> t;
	while (t-- > 0) {
        string z;
        cin >> z;
        int cc[10];
        for (int i=0; i<10; i++) cc[i] = 0;
        for (int i=0; i<z.size(); i++) cc[z[i] - '0']++;
        bool nonzero = false;
        for (int i=9; i>0; i--) {
            for (int j=0; j<cc[i]; j++) {
                    nonzero = true;
                    cout << i;
            }
        }
        if (!nonzero) cout << 0;
        else for (int i=0; i<cc[0]; i++) cout << 0;
        cout << endl;
	}
	return 0;
}
