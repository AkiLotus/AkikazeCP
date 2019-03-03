#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int t, cas = 0;
	cin >> t;
	while (t-- > 0) {
		cas++;
		cout << "Case #" << cas << ": ";
		int n;
		cin >> n;
		float x[n], y[n], z[n], vx[n], vy[n], vz[n];
		float xg = 0, yg = 0, zg = 0, vxg = 0, vyg = 0, vzg = 0;
		for (int i=0; i<n; i++) {
			cin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i];
			xg += x[i]; yg += y[i]; zg += z[i]; vxg += vx[i]; vyg += vy[i]; vzg += vz[i];
		}
		xg /= n; yg /= n; zg /= n; vxg /= n; vyg /= n; vzg /= n;
		if (vxg != 0 || vyg != 0 || vzg != 0) {
			float tim = - (xg*vxg + yg*vyg + zg*vzg) / (vxg*vxg + vyg*vyg + vzg*vzg);
			if (tim < 0) tim = 0;
			float res = sqrt((xg+tim*vxg)*(xg+tim*vxg) + (yg+tim*vyg)*(yg+tim*vyg) + (zg+tim*vzg)*(zg+tim*vzg));
			cout << fixed << setprecision(2) << res << " ";
			if (tim != 0) cout << fixed << setprecision(2) << tim << endl;
			else cout << "0.00" << endl;
		}
		else {
			float res = sqrt(xg*xg + yg*yg + zg*zg);
			cout << fixed << setprecision(2) << res << " 0.00" << endl;
		}
	}
	return 0;
}
