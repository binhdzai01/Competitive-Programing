
// binhdzai

#include <bits/stdc++.h>
#define maxn 1007
#define ft first
#define sd second
#define all(v) (v.begin(), v.end())
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int n, m, c[maxn], sum;
double x, ans, dp[101][10001];
void read()
{
    cin >> n >> x;
    dp[0][0] = 1;
    x /= 2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        sum += c[i];
    }
}

void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            for (int k = c[i]; k <= sum; ++k)
            {
                dp[j][k] += dp[j - 1][k - c[i]] * j / (1.0 * (n - j + 1));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            ans += dp[i][j] * min(((double)(n) / i + 1) * x, (double(j) / (double)(i)));
        }
    }
    cout << fixed << setprecision(17) << ans;
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}