#include <bits/stdc++.h>
using namespace std;

int n;
int m;
priority_queue<long long ,vector<long long>, less<long long> > pq;

int f(int a,int b, int c,int x)
{
    return a * x * x + b * x + c;
}
int an[10005],bn[10005],cn[10005];
int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> an[i] >> bn[i] >> cn[i];
    }
    for(int i = 0;i < n;i++)
    {
        for(int x = 1;x <= m;x++)
        {
            int now = f(an[i],bn[i],cn[i],x);
            if(pq.size() < m)
            {
                pq.push(now);
            }
            else
            {
                if(now < pq.top())
                {
                    pq.pop();
                    pq.push(now);
                }
            }
        }
    }
    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    for(int i = m - 1;i >= 0;i--)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}