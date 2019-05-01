#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

/**
	Tìm suffix array. Độ phức tạp O(n log² n)
**/

const int N = 200005;
int n, sa[N], ra[N], rb[N], G;
char a[N];

bool cmp(int x, int y) {
 if (ra[x]!=ra[y]) return ra[x]<ra[y];
 return ra[x+G]<ra[y+G];
}

main() {
 scanf("%s", a+1);
 n=strlen(a+1);

 for (int i=1; i<=n; i++)
 { sa[i]=i; ra[i]=a[i]; }

 for (G=1; G<=n; G*=2) {
 sort(sa+1, sa+n+1, cmp);
 for (int i=1; i<=n; i++)
 rb[sa[i]] = rb[sa[i-1]] + cmp(sa[i-1], sa[i]);
 for (int i=1; i<=n; i++)
 ra[i] = rb[i];
 if (ra[sa[n]]==n) break;
 }

 for (int i=1; i<=n; i++)
 printf("%d\n", sa[i]-1);
}
