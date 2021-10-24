
// binhdzai

#include <bits/stdc++.h>
#define maxn 2005
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
typedef pair<int, int> ii;
int n, m, a[maxn];
int ans = 0;
bool visit[maxn];
int d[maxn];
vector<ii> adj[maxn];
void read()
{
    cin >> n >> m;
    foru(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
}
void dfs(int u)
{
    visit[u] = true;
    ans++;
    int mMin = 1e9 + 6;
    for (auto edge : adj[u])
    {
        int v = edge.ft;
        int z = edge.sd;
        if (!visit[v])
        {
            mMin = min(mMin, z);
        }
    }
    for (auto edge : adj[u])
    {
        int v = edge.ft;
        int z = edge.sd;
        if (d[v] == d[u] + z && z == mMin && visit[v] == false)
        {
            dfs(v);
        }
    }
}

void dijkstra(int u)
{
    priority_queue<ii> hmin;
    memset(d, 60, sizeof(d));
    d[u] = 0;
    hmin.emplace(0, u);
    while (hmin.size())
    {
        int u = hmin.top().sd;
        hmin.pop();
        for (auto edge : adj[u])
        {
            int v = edge.ft;
            int z = edge.sd;
            if (d[v] > d[u] + z)
            {
                d[v] = d[u] + z;
                hmin.emplace(-d[v], v);
            }
        }
    }
}

void solve()
{
    foru(i, 1, n)
    {
        dijkstra(i);
        memset(visit, false, sizeof(visit));
        dfs(i);
        foru(j, 1, n)
        {
            if (!visit[j] && d[j] > 1e9)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("./../input.txt", "r", stdin);
    freopen("./../output.txt", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}