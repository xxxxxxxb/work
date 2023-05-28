#include <bits/stdc++.h>
using namespace std;
#define FIN(x) for(int i = 1;i <= x;i++)
#define FJN(x) for(int j = 1;j <= x;j++)
int n,m;
int ans[1005][1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    n = (1 << m);
    ans[1][1] = 1;
    int now = 1;
    FIN(m)
    {
        FIN(now)    
        {
            FJN(now)
            {
                ans[i][j + now] = ans[i + now][j] = ans[i][j] + now;
                ans[i + now][j+now] = ans[i][j];
            }
        }
        now <<= 1;
    }
    FIN(n)
    {
        FJN(n)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}