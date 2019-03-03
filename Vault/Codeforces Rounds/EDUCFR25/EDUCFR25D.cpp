#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	vector<int> query;
	int ccT[26], cc[26];
	for (int i=0; i<26; i++) {
        ccT[i] = 0; cc[i] = 0;
	}
	for (int i=0; i<s.size(); i++) {
        if (s[i] == '?') query.push_back(i);
        else cc[int(s[i])-97]++;
	}
	for (int i=0; i<t.size(); t++) {
        cc[int(t[i])-97]++;
	}
	string seq = "";
	int starting[26];
	for (int i=25; i>=0; i--) {
        seq.insert(0, cc[i], char(97+i));
        starting[i] = 0;
        for (int j=i+1; j<26; j++) starting[j] += cc[i];
	}

	return 0;
}
