vi Z_Algo(string S) {
	vi z(S.size()); i64 x = 0, y = 0;
	for (i64 i=1; i<S.size(); i++) {
		z[i] = max(0LL, min(z[i-x], y-i+1));
		while (i+z[i] < S.size() && S[z[i]] == S[i+z[i]]) {
			x = i; y = i + z[i]; z[i]++;
		}
	}
	return z;
}