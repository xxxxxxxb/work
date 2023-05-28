#include <bits/stdc++.h>
using namespace std;

long long n,ans[80];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(ans,-1,sizeof(ans));
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    while(true)
    {
        cin >> n;
        if(n==0)break;
        for(int i = 1;i <= n;i++)
        {
            if(ans[i] != -1)
            {
                continue;
            }
            else
            {
                ans[i] = ans[i-1]+ans[i-2]+ans[i-3];
            }
        }
        cout << ans[n] << '\n';
    }
    return 0;
}