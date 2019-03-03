#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int a[maxn][56];
int n, dem = 0;
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    cin >> s;
    n = s.length() - 1;
    memset(a, 0, sizeof(a));
    for (int i = 0; i <= 40; i++)
        {
            a[n+1][i] = n+1;
            cout << a[n+1][i] << " ";
        }
    for (int i = n; i >= 0; i --)
        {
            for (int j = 28; j >= 0; j--)
                a[i][j] = a[i+1][j];
            a[i][s[i]-'a'] = i;
        }
    for (int i = 0; i <= n; i++)
        for (int j = 28; j >= 0; j--)
        if (a[i][j] < n+1)
    {
        i = a[i][j];
        dem ++;
        break;
    }
    cout << dem;
    return 0;
}
