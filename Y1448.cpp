#include <bits/stdc++.h>
using namespace std;
struct T
{
    int x, y;
};
deque<T> q, qq;
const int N = 505;
char an[N][N];
int m, n, t;
char a[5] = "\\/\\/";
long long vis[N][N];
int dx[4] = {-1, 1, 1, -1};
int dy[4] = {-1, -1, 1, 1};
int gx[4] = {-1, 0, 0, -1};
int gy[4] = {-1, -1, 0, 0};
void s()
{
    memset(vis, 0x3f, sizeof(vis));
    vis[0][0] = 0;
    q = qq;
    q.push_front({0, 0});
    while (!q.empty())
    {
        T old = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = old.x + dx[i],
                ny = old.y + dy[i],
                gnx = old.x + gx[i],
                gny = old.y + gy[i];
            // q.pop_front();
            if (nx < 0 || nx > n || ny < 0 || ny > m)
                continue;
            if (an[gnx][gny] == a[i])
            {
                if (vis[old.x][old.y] >= vis[nx][ny])
                {
                    continue;
                }
                else
                {
                    q.push_front({nx, ny});
                    vis[nx][ny] = vis[old.x][old.y];
                }
            }
            else
            {
                if (vis[old.x][old.y] + 1 >= vis[nx][ny])
                {
                    continue;
                }
                else
                {
                    q.push_back({nx, ny});
                    vis[nx][ny] = vis[old.x][old.y] + 1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> an[i];
        }
        if (((m + n) % 2) == 1)
            cout << "NO SOLUTION\n";
        else
        {
            s();
            cout << vis[n][m] << '\n';
        }
    }
    return 0;
}