#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll strtoll(string z) {
	ll result = 0, sign = 1, i = 0;
	if (z[0] == '-') {
		i = 1; sign = -1;
	}
	for (; i<z.size(); i++) {
		result *= 10;
		result += (z[i] - '0');
	}
	return result * sign;
}

string rowName(ll z) {
    z--; string p = "";
    if (z < 26) {
        p = "A"; p[0] = 'A' + z;
    }
    else {
        z++;
        while (z > 0) {
            int tmp = z % 26;
            z /= 26;
            if (tmp == 0) {
                z--; p.insert(0, 1, 'Z');
            }
            else {
                char q = 'A' + (tmp - 1);
                p.insert(0, 1, q);
            }
        }
    }
    return p;
}

ll rowNum(string z) {
    ll res = 0, mul = 1;
    for (ll i=z.size()-1; i>=0; i--) {
        res += mul * (z[i] - 'A' + 1);
        mul *= 26;
    }
    return res;
}

int main() {
	int n;
	cin >> n;
	while (n-- > 0) {
        string z; cin >> z;
        if (z[0] == 'R' && z[1] >= '0' && z[1] <= '9' && z.find("C") > 1) {
            string val = z, dest;
            int colNo;
            string Rtmp, Ctmp;
            int check;
            colNo = 0; check = 0;
            dest = ""; Rtmp = ""; Ctmp = "";
            int len = val.size();
            for (int i=0; i<len; i++) {
                if (val[i] == 'C') {
                    check++;
                }
                if (check == 0 && val[i] != 'R') {
                    Rtmp += val[i];
                }
                if (check == 1 && val[i] != 'C') {
                    Ctmp += val[i];
                }
            }
            int tmp2 = Ctmp.size();
            for (int i=0; i<tmp2; i++) {
                colNo += int(Ctmp[i])-48;
                if (i != tmp2-1) {
                    colNo *= 10;
                }
            }
            if (colNo < 27) {
                dest += char(64+colNo);
            }
            else {
                while (colNo > 0) {
                    colNo--;
                    int tmp = colNo % 26;
                    dest.insert(dest.begin(), char(65+tmp));
                    colNo /= 26;
                }
            }
            dest += Rtmp;
            cout << dest << endl;
        }
        else {
            ll m = 1;
            while (z[m] < '0' || z[m] > '9') m++;
            string row = "", col = "";
            for (ll i=0; i<m; i++) row += z[i];
            for (ll i=m; i<z.size(); i++) col += z[i];
            ll rn = rowNum(row);
            cout << "R" << col << "C" << rn << endl;
        }
	}
	return 0;
}
