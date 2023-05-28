#include <bits/stdc++.h>
using namespace std;

long long x,y,z,ans[105],bns[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y >> z;
    for(int i = 1;i <= x;i++)
    {
        ans[i] = 1;
        bns[i] = 0;
    }
    for(int i = x + 1;i <= z+1;i++)
    {
        bns[i] = y * ans[i - x];
        ans[i] = bns[i - 2] + ans[i-1];
    }
    cout << ans[z+1];
    return 0;
}