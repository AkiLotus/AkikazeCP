#include <stdio.h>

int par[2309];
int n;
int anc(int p){
    if (par[p]==p) return p;
    else return par[p] = anc(par[p]);
}

void join(int p, int q){
    par[anc(p)] = anc(q);
}

main(){
    int i, p, q, m;
    scanf("%d", &n);
    for (i=1; i<=n; i++) par[i] = i;

    scanf("%d", &m);
    for (i=1; i<=m; i++) {
        scanf("%d%d", &p, &q);
        join(p, q);
    }

    for (i=1; i<=n; i++) printf("%3d,", i); printf("\n");
    for (i=1; i<=n; i++) printf("%3d,", anc(i)); printf("\n");
}

/**
Sample Input
5
3
1 2
4 5
1 5

(giải thích : có 5 điểm, nối điểm 1 với 2, 4 với 5, 1 với 5)

Sample Output
1, 2, 3, 4, 5,
5, 5, 3, 5, 5,

(giải thích : các đỉnh 1,2,4,5 có cùng màu với đỉnh 5, 3 chỉ cùng màu với chính nó)
**/
