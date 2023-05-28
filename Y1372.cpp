#include <bits/stdc++.h>
using namespace std;

int n,m,a;
multiset<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> m;
        while(m--)
        {
            cin >> a;
            s.insert(a);
        }
        auto maxn = s.begin(),minn = s.end();
        minn--;
        cout << *maxn << ' ' << *minn << '\n';
        s.erase(maxn);
        s.erase(minn);
    }
}