vector<int> Z_Algo(string S) {
	vector<int> z(S.size()); int x = 0, y = 0;
	for (int i=1; i<S.size(); i++) {
		z[i] = max(0LL, min(z[i-x], y-i+1));
		while (i+z[i] < S.size() && S[z[i]] == S[i+z[i]]) {
			x = i; y = i + z[i]; z[i]++;
		}
	}
	return z;
}