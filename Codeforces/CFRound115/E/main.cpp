
// binhdzai

#include <bits/stdc++.h>
#define maxn 1007
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define int long long
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define endl "\n";
using namespace std;
const int N = 1e3 + 5;

bool a[N][N];
// up : (-1, 0)
// left : (0, -1)
int go(int sx, int sy, int dx, int dy)
{
    int x = sx + dx;
    int y = sy + dy;
    int cnt = 1;
    // db(x, y, a[x][y]);
    while (not a[x][y])
    {
        ++cnt;
        swap(dx, dy);
        x += dx;
        y += dy;
    }
    return cnt;
}
int calc(int x, int y)
{
    int up1 = go(x, y, -1, 0), dn1 = go(x, y, 0, 1);
    int up2 = go(x, y, 0, -1), dn2 = go(x, y, 1, 0);
    // db(x, y, up1, dn1, up2, dn2);
    return up1 * dn1 + up2 * dn2 - 1;
}
int n, m, q;
int pro(int dx, int dy)
{
    int d = min(dx, dy);
    return (d * 2 - 1) * 2 + (dx != dy) - 1;
}
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        a[i][0] = a[i][m + 1] = 1;
    for (int i = 1; i <= m; ++i)
        a[0][i] = a[n + 1][i] = 1;

    int x, y;
    // co res
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int p = pro(i, j);
            // db(i, j, p);
            res += p;
        }
    }
    // db(res);
    int c;
    for (int i = 0; i < q; ++i)
    {
        cin >> x >> y;
        c = calc(x, y);
        // db(x, y, c);
        if (a[x][y] == 0)
        {
            a[x][y] = 1;
            res -= c;
        }
        else
        {
            a[x][y] = 0;
            res += c;
        }
        cout << res << "\n";
    }
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}