#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 100005
long n, m, t, T, Root;
long Parent[21][N], Level[N]; //
long presum[N];

long level(long u){ // recursion because n<=1000
   if (u==Root) return 1;
   if (Level[u]) return Level[u];
   return Level[u]=level(Parent[0][u])+1;
}

void enter(){
   for(long i=1; i<n; i++) {
      long a, l; scanf("%d%d", &a, &l);
      presum[i] = presum[a] + l;
      Parent[0][i]= a;
   }
   f0(i,n) if (Parent[0][i]==0) Root=i;
}

long lca(long x, long y){
   #define k(x) Parent[k][x]
   for (long k=20; k>=0; k--) if (level(k(x))>=level(y)) x=k(x);
   for (long k=20; k>=0; k--) if (level(k(y))>=level(x)) y=k(y);
   for (long k=20; k>=0; k--) if (k(x)!=k(y)) x=k(x), y=k(y);
   while (x!=y) { x=Parent[0][x], y=Parent[0][y]; }
   #undef k
   return x;
}

main(){
   scanf("%d", &n);
   while(n != 0){
      scanf("%d", &n);
      f0(i,n) Parent[0][i]=Level[i]=presum[i]=0;
      enter();
      Parent[0][Root]=Root;

      for (long k=1; k<=20; k++)
      for (long i=1; i<=n; i++)
      Parent[k][i]=Parent[k-1][Parent[k-1][i]];

      scanf("%d", &m);
      while (m--){
         long x, y;
         scanf("%d%d", &x, &y);
         long xx = lca(x, y);
         printf("%d ", presum[x]+presum[y]-presum[xx]);
      }
      printf("\n");
      scanf("%d", &n);
   }
}
