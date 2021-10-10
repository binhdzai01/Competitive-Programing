
// binhdzai

#include <bits/stdc++.h>
#define maxn 50005
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
int k;
int dp[maxn][505];
vector<int> adj[maxn];
void read()
{
    cin >> n >> k;
    foru(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
int ans = 0;
void dfs(int u, int fa)
{
    dp[u][0] = 1;
    for (auto v : adj[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        foru(i, 0, k - 1)
        {
            ans += dp[v][i] * dp[u][k - i - 1];
        }
        foru(i, 0, k - 1)
        {
            dp[u][i + 1] += dp[v][i];
        }
    }
}

void solve()
{
    dfs(1, 0);
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
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}