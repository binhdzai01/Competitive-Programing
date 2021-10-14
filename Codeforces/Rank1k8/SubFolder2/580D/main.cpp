
// binhdzai

#include <bits/stdc++.h>
#define maxn 19
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
int n, m, a[maxn], k;
int c[maxn][maxn];
void read()
{
    cin >> n >> m >> k;
    foru(i, 1, n) cin >> a[i];
    while (k--)
    {
        int a, b, x;
        cin >> a >> b >> x;
        c[a][b] += x;
    }
}
int getbit(int x, int i)
{
    return (x >> i) & 1;
}
int f[(1 << maxn)][maxn];
void solve()
{
    int ans = 0;
    memset(f, -60, sizeof(f));
    foru(i, 1, n)
    {
        f[1 << (i - 1)][i] = a[i];
    }
    foru(x, 1, (1 << n) - 1)
    {
        foru(i, 1, n)
        {
            if (!getbit(x, i - 1))
                continue;
            if (__builtin_popcount(x) == m)
            {
                // cout << f[x][i] << endl;
                ans = max(ans, f[x][i]);
            }
            foru(j, 1, n)
            {
                if (getbit(x, j - 1))
                    continue;
                int y = x + (1 << (j - 1));
                f[y][j] = max(f[y][j], f[x][i] + c[i][j] + a[j]);
            }
        }
    }
    cout << ans;
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    int test;
    cin >> test;
    while (test--)
    {
        read();
        solve();
    }
    return 0;
}