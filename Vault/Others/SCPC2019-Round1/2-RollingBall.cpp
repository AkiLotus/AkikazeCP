#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const long double Pi = 3.141592653589793116L;
int test = 0;
int R, S, E, N;
vector<int> l, r, h;

void Input() {
	cin >> R >> S >> E >> N;
	l.clear(); r.clear(); h.clear();
	l.resize(N); r.resize(N); h.resize(N);
	for (int i=0; i<N; i++) cin >> l[i] >> r[i] >> h[i];
}

void Solve() {
	long double flatSurface = E - S - N * R * 2;
	long double rotation = 0;
	for (int i=0; i<N; i++) {
		if (h[i] >= R) {
			flatSurface += (h[i] - R) * 2;
			rotation += Pi;
		}
		else {
			long double x_dist = 1.0L * R - sqrt(R * R - (R - h[i]) * (R - h[i]));
			rotation += acos(1.0L * (R - h[i]) / R) * 2;
			flatSurface += x_dist * 2;
		}
	}
	cout << "Case #" << (++test) << endl;
	cout << fixed << setprecision(12) << (flatSurface + rotation * R) << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int T; cin >> T; while (T--) {Input(); Solve();} return 0;
}