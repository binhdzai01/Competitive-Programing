
// binhdzai

#include <bits/stdc++.h>
#define maxn 100007
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
int n, m, a[maxn];
int dp[maxn][533];
void read()
{
    cin >> n;
    foru(i, 1, n) cin >> a[i];
    reverse(a + 1, a + 1 + n);
    foru(i, 1, n) a[i] += a[i - 1];
}

void solve()
{
    int block = sqrt(2 * n + 1);
    foru(i, 0, n) dp[i][0] = 1e18;
    foru(i, 1, n)
    {
        foru(j, 1, block)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (i < j)
                continue;
            int x = dp[i - j][j - 1];
            int cur = a[i] - a[i - j];
            if (cur < x)
            {
                dp[i][j] = max(dp[i][j], cur);
            }
        }
    }
    ford(i, block, 1)
    {
        if (dp[n][i] != 0)
        {
            cout << i << endl;
            break;
        }
    }
    foru(i, 0, n)
    {
        foru(j, 0, block) dp[i][j] = 0;
    }
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("./../input.txt", "r", stdin);
    freopen("./../output.txt", "w", stdout);
    int test;
    cin >> test;
    while (test--)
    {
        read();
        solve();
    }
    return 0;
}