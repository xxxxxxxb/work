#include <bits/stdc++.h>
using namespace std;

priority_queue<long long , vector<long long>,greater<long long> > pq;
int n;
long long ans;

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int s;
        cin >> s;
        pq.push(s);
    }
    for(int i = 1;i < n;i++)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b); 
        ans += a + b;
    }
    cout << ans;
    return 0;
}