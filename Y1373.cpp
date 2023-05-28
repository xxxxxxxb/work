#include <bits/stdc++.h>
using namespace std;

struct node
{
    int lake;
    int fish;
    bool operator<(const node &b) const
    {
        return fish < b.fish;
    }
};
int n, m, T, t0,ans,maxn;
int fish[105], dis[105], tito[105];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> fish[i];
    for (int i = 1; i <= n; i++)
        cin >> dis[i];
    for (int i = 1; i < n; i++)
        cin >> tito[i];
    cin >> T;
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        priority_queue<node> pq;
        int tn = T - t0;
        for (int j = 1; j <= i; j++)
        {
            pq.push({j,fish[j]});
        }
        while(tn > 0&& pq.top().fish > 0)
        {
            node now = pq.top();
            pq.pop();
            ans += now.fish;
            now.fish -= dis[now.lake];
            pq.push(now);
            tn--;
        }
        //cout << ans << ' ';
        t0 += tito[i];
        if(ans > maxn)
            maxn = ans;
    }
    cout << maxn;
    return 0;
}