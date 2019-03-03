#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int k, b, m;
	cin >> s >> k >> b >> m;
	int removal[10];
	for (int i=0; i<10; i++) {
		removal[i] = i % m;
		for (int j=1; j<k; j++) removal[i] = (removal[i] * b) % m;
	}
	int zz = 0;
	for (int i=0; i<k; i++) {
        zz *= b;
        zz += (s[i] - '0');
        zz %= m;
	}
	int answer = zz;
	for (int i=k; i<s.size(); i++) {
        int tmp = s[i-k] - '0';
        zz -= removal[tmp];
        while (zz < 0) zz += m;
        zz *= b;
        zz += (s[i] - '0');
        zz %= m;
        answer += zz;
	}
	cout << answer;
	return 0;
}

