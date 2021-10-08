
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
int a[210], b[210], c[210], dp[210][210][210];
void read()
{
}

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 1; i <= x; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= y; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= z; i++)
    {
        cin >> c[i];
    }
    sort(a + 1, a + x + 1);
    sort(b + 1, b + y + 1);
    sort(c + 1, c + z + 1);
    int ans = 0;
    for (int i = x + 1; i >= 0; i--)
    {
        for (int j = y + 1; j >= 0; j--)
        {
            for (int k = z + 1; k >= 0; k--)
            {
                dp[i][j][k] = max(dp[i + 1][j + 1][k] + a[i] * b[j], max(dp[i + 1][j][k + 1] + a[i] * c[k], max(dp[i][j + 1][k + 1] + b[j] * c[k], 0ll)));
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans;
    return;
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}