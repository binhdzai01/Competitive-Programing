
// binhdzai

#include <bits/stdc++.h>
#define maxn 105
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
int dp[maxn][maxn][2];
void read()
{
    cin >> n;
    foru(i, 1, n) cin >> a[i];
}

void solve()
{
    int cntEven = n / 2;
    int cntOdd = n - cntEven;
    memset(dp, 60, sizeof(dp));
    if (a[1] % 2 || a[1] == 0)
        dp[1][0][1] = 0;
    if (a[1] % 2 == 0 || a[1] == 0)
        dp[1][1][0] = 0;
    foru(i, 2, n)
    {
        foru(j, 0, min(i, cntEven))
        {
            if ((a[i] % 2 == 0 || a[i] == 0) && j > 0)
                dp[i][j][0] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + 1);
            if (a[i] % 2 == 1 || a[i] == 0)
                dp[i][j][1] = min(dp[i - 1][j][1], dp[i - 1][j][0] + 1);
        }
    }
    cout << min(dp[n][cntEven][1], dp[n][cntEven][0]);
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