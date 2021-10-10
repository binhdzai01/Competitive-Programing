
// binhdzai

#include <bits/stdc++.h>
#define maxn 205
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
int dp[maxn][maxn * 2];
void read()
{
    cin >> n;
    foru(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
}

void solve()
{
    memset(dp, 60, sizeof(dp));
    int ans = 2 * n + 1;
    foru(i, 0, 2 * n) dp[0][i] = 0;
    foru(i, 1, n)
    {
        foru(j, 1, n * 2)
        {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(j - a[i]));
        }
    }
    cout << dp[n][2 * n] << endl;
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