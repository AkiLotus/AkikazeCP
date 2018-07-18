// https://www.codechef.com/MAY18A/problems/NONCONVX

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point {
	ll x, y;
      int ind;
	bool operator <(const point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

int check(point a, point b, point c) {
      ll val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

      if (val == 0) return 0;       // collinear
      return (val > 0) ? -1: 1;     // counter-clockwise and clockwise
}

void solve() {
      int n, k, r;
      cin >> n >> k >> r;
      vector<point> p(n), out(n);
      for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
            p[i].ind = i+1;
            out[i] = p[i];
      }

      sort(p.begin(), p.end());

      // find CVX hull begins

      vector<point> hull(n*2);
      vector<int> ch(n+1, 0);
      k = 0;
      for (int i = 0; i < n; i++) {
            while (k >= 2 && check(hull[k-2], hull[k-1], p[i]) <= 0) k--;
            hull[k++] = p[i];
      }
      for (int i = n-1, t = k+1; i > 0; i--) {
            while (k >= t && check(hull[k-2], hull[k-1], p[i-1]) <= 0) k--;
            hull[k++] = p[i-1];
      }
      hull.resize(k-1);       // because first point coincides with last

      // CVX hull ends

      cout << hull.size() << '\n';
      for (int i = 0; i < hull.size(); i++) {
            cout << hull[i].ind << ' ';
      }
      cout << '\n';
      for (int i = 0; i < n; i++) {
            cout << out[i].x << " " << out[i].y << '\n';
      }
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      srand(time(NULL));

      int t; cin >> t;
      while (t--) {
            solve();
      }

      return 0;
}
