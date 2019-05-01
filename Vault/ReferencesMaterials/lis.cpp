#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

int n, answer=0;
int a[1230997];
int b[1230997];
int f[1230997];
vector<int> T;

main(){
   scanf("%d", &n);
   //for (int i=1; i<=n; i++) scanf("%d", &a[i]);

   srand(n*1000);
   for (int i=1; i<=n; i++) a[i]=(rand()%100-10)*10;
   for (int i=1; i<=n; i++) printf(i==n?"%d\n":"%d ", a[i]);

   for (int i=1; i<=n; i++){
      f[i]=lower_bound(b+1, b+answer+1, a[i])-b;
      maximize(answer, f[i]);
      b[f[i]]=a[i];
   }

   printf("%d\n", answer);

   int require = answer;
   for (int i=n; i>=1; i--)
   if (f[i]==require){
      T.push_back(a[i]);
      require--;
   }

   reverse(T.begin(), T.end());
   for (int i=0; i<T.size(); i++)
   printf("%d ", T[i]);
   printf("\n");
}
