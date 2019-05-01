#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 400005
char s[N];
int n, Rank[21][N], SA[21][N], SA1[N];

void radix_sort(int a[], int b[], int n, int r[], int K){
   vector<int> Count(K+1), Start(K+1);
   f0(i,n) Count[r[a[i]]]++;
   f1(i,K) Start[i]=Start[i-1]+Count[i-1];
   f0(i,n) b[Start[r[a[i]]]++]=a[i];
}

main(){
   gets(s); n=strlen(s);
   f0(i,n) Rank[0][i]=s[i];
   f0(i,n) SA1[i]=i;
   radix_sort(SA1, SA[0], n, Rank[0], 128);
   int Name=128, Gap=1;
   f1(k,17) {
      radix_sort(SA[k-1], SA1, n, Rank[k-1]+Gap, Name);
      radix_sort(SA1, SA[k], n, Rank[k-1], Name);

      Name=0;
      f0(i,n) {
         if (i==0 || Rank[k-1][SA[k][i]]!=Rank[k-1][SA[k][i-1]]
            || Rank[k-1][SA[k][i]+Gap]!=Rank[k-1][SA[k][i-1]+Gap]) Name++;
         Rank[k][SA[k][i]]=Name;
      }
      Gap*=2;
   }
   f0(i,n) printf("%d\n", SA[17][i]);
}
