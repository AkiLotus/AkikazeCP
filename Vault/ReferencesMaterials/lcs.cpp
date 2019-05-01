#include <stdio.h>
#include <string.h>

int m, n;
char a[12309];
char b[12309];
int F[2309][2309];
bool FF[2309][2309];

int max(int a, int b){ return a>b?a:b; }

int f(int m, int n){
   if (m==0 || n==0) return 0;
   if (FF[m][n]) return F[m][n];

   int r;
   if (a[m]==b[n]) r = f(m-1,n-1)+1;
   else r = max(f(m-1,n), f(m,n-1));
   FF[m][n]=true;
   F[m][n]=r;
   return r;
}

main(){
   scanf("%s%s", a+1, b+1);
   m=strlen(a+1);
   n=strlen(b+1);
   printf("%d\n", f(m, n));
}
