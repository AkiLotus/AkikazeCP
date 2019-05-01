#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 100005
int n, m, t, T, Root;
int Parent[21][N], Level[N]; //

int level(int u){ // recursion because n<=1000
   if (u==Root) return 1;
   if (Level[u]) return Level[u];
   return Level[u]=level(Parent[0][u])+1;
}

void enter(){
   f1(i,n) {
      int x, y; scanf("%d", &y);
      while (y--){ scanf("%d", &x); Parent[0][x]=i; }
   }
   f1(i,n) if (Parent[0][i]==0) Root=i;
}

int lca(int x, int y){
   #define k(x) Parent[k][x]
   for (int k=20; k>=0; k--) if (level(k(x))>=level(y)) x=k(x);
   for (int k=20; k>=0; k--) if (level(k(y))>=level(x)) y=k(y);
   for (int k=20; k>=0; k--) if (k(x)!=k(y)) x=k(x), y=k(y);
   while (x!=y) { x=Parent[0][x], y=Parent[0][y]; }
   #undef k
   return x;
}

main(){
   scanf("%d", &T);
   f1(t,T){
      scanf("%d", &n);
      f1(i,n) Parent[0][i]=Level[i]=0; // init
      enter();
      Parent[0][Root]=Root;

      for (int k=1; k<=20; k++)
      for (int i=1; i<=n; i++)
      Parent[k][i]=Parent[k-1][Parent[k-1][i]];

      printf("Case %d:\n", t);
      scanf("%d", &m);
      while (m--){
         int x, y;
         scanf("%d%d", &x, &y);
         printf("%d\n", lca(x, y));
      }
   }
}
