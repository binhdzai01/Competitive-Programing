
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
int n, m, a[maxn], preXor[maxn];
unordered_map<int, int> M;
int dp[maxn][65];
const int mod = 1e9 + 7;
void read()
{
    cin >> n;
    foru(i, 1, n)
    {
        cin >> a[i];
        preXor[i] = (preXor[i - 1] ^ a[i]);
    }
}

void solve()
{
    foru(i, 1, n) dp[i][1] = 1;
    foru(j, 2, 55)
    {
        int cur = (1ll << (j - 1)) - 1;
        M.clear();
        foru(i, 1, n)
        {
            int x = (preXor[i] & cur);
            dp[i][j] = M[x];
            M[x] += dp[i][j - 1];
            M[x] %= mod;
        }
    }
    int ans = 0;
    foru(i, 1, 55)
    {
        ans = (ans + dp[n][i]) % mod;
    }
    int cur = 1, xXor = 0;
    ford(i, n, 1)
    {
        xXor ^= a[i];
        if (xXor == 0)
        {
            ans = (ans + dp[i - 1][55] * cur % mod) % mod;
            cur = cur * 2 % mod;
        }
    }
    cout << ans << endl;
    foru(i, 1, n)
    {
        foru(j, 1, 55) dp[i][j] = 0;
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