#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
Bài toán
Tìm tập phủ đỉnh cực tiểu trên đồ thị hai phía.
Có thể hiểu đề bài rằng: Trong một tập đỉnh, một đỉnh nằm trong tập thì phủ tất cả các cạnh kề với nó. Cần chọn tập có ít đỉnh nhất sao cho tất cả các cạnh đều bị phủ.
Độ phức tạp
sau khi chạy bộ ghép cực đại, mất thêm O(m+n) để tìm tập phủ đỉnh cực tiểu
**/

#define long long long
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)

#define N 2003
int m, n, q;
vector<int> a[N]; //
int Assigned[N], Visited[N]; //
bool Choosed[N]; //

bool visit(int u, int Key){
   if (Visited[u]==Key) return false; Visited[u]=Key;
   for (int i=0; int v=a[u][i]; i++)
   if (!Assigned[v] || visit(Assigned[v], Key))
   { Assigned[u]=v; Assigned[v]=u; return true; }
   return false;
}

void konig(){
   queue<int> qu;

   f1(i,m) if (!Assigned[i]) qu.push(i);
   f1(i,n) if (!Assigned[N-i]) qu.push(N-i);

   while (qu.size()){
      int u=qu.front(); qu.pop();
      for (int i=0; int v=a[u][i]; i++)
      if (!(Choosed[v]++)) qu.push(Assigned[v]);
   }

   f1(i,m) if (Assigned[i] && !Choosed[i] && !Choosed[Assigned[i]])
   Choosed[i]=true;
}

main(){
   scanf("%d%d%d", &m, &n, &q);
   if (m+n+q==0) return 0;
   f1(i,q){
      int x, y;
      scanf("%d%d", &x, &y);
      a[x].push_back(N-y);
      a[N-y].push_back(x);
   }
   f1(i,m) a[i].push_back(0);
   f1(i,n) a[N-i].push_back(0);

   static int cnt=0; int Count=0;
   f1(i,m) if (!Assigned[i]) visit(i, ++cnt);
   f1(i,m) if (Assigned[i]) Count++;
   cout << Count;

   konig();
   f1(i,m) if (Choosed[i]) printf(" r%d", i);
   f1(i,n) if (Choosed[N-i]) printf(" c%d", i);
   printf("\n");

   f1(i,m) a[i].clear();
   f1(i,n) a[N-i].clear();
   memset(Assigned, 0, sizeof Assigned);
   memset(Choosed, 0, sizeof Choosed);

   main();
}
