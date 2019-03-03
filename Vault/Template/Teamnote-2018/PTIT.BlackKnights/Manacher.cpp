i64 ManacherProcess(string s) {
	i64 n = s.size(), res = 0;
	vi odd(n, 0), even(n, 0);
	for (i64 i=0, l=0, r=-1; i<n; i++) {
		i64 x = 0; if (i <= r) x = min(odd[l+r-i], r-i);
		while (0 <= i-x-1 && i+x+1 < n && s[i-x-1] == s[i+x+1]) x++;
		odd[i] = x; res += (x + 1);
		if (i + x > r) {l = i - x; r = i + x;}
	}
	for (i64 i=1, l=0, r=0; i<n; i++) {
		if (s[i-1] != s[i]) continue;
		i64 x = 0; if (i <= r) x = min(even[l+r-i+1], r-i);
		while (0 <= i-x-2 && i+x+1 < n && s[i-x-2] == s[i+x+1]) x++;
		even[i] = x; res += (x + 1);
		if (i + x > r) {l = i-1 - x; r = i + x;}
	}
	return res;
}