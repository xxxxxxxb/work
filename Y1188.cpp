#include <bits/stdc++.h>
using namespace std;

int a, ans[(int)1e6 + 7], n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(ans, -1, sizeof(ans));
    ans[1] = 1;
    ans[2] = 1;
    cin >> n;
    while (n--)
    {
        cin >> a;
        for (int i = 1; i <= a; i++)
        {
            if (ans[i] != -1)
                continue;
            else
            {
                ans[i] = (ans[i - 1] + ans[i - 2]) % 1000;
            }
        }
        cout << ans[a] << '\n';
    }
    return 0;
}