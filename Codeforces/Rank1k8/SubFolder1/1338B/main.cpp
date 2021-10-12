
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
vector<int> adj[maxn];
bool dp[maxn][2];
int root;
int mmin = 1, mmax;
void read()
{
    cin >> n;
    mmax = n - 1;
    foru(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
}
void dfs(int u, int fa)
{
    if (adj[u].size() == 1)
    {
        dp[u][0] = true;
    }
    int cnt = 0;
    for (auto v : adj[u])
    {

        if (v == fa)
            continue;
        dfs(v, u);
        if (adj[v].size() == 1)
            cnt++;
        if (dp[v][0] == true)
            dp[u][1] = true;
        if (dp[v][1] == true)
            dp[u][0] = true;
    }
    if (cnt)
        mmax -= cnt - 1;
    if (dp[u][0] && dp[u][1])
    {
        mmin = 3;
    }
}

void solve()
{
    foru(i, 1, n)
    {
        if (adj[i].size() > 1)
            root = i;
    }
    dfs(root, 0);
    cout << mmin << " " << mmax;
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