
// binhdzai

#include <bits/stdc++.h>
#define maxn 400007
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
int deg[maxn];
int cnt[maxn];
vector<int> adj[maxn];
int k;
void read()
{
    cin >> n >> k;
    foru(i, 1, n) adj[i].clear(), deg[i] = 0;
    foru(i, 1, k) cnt[i] = 0;
    foru(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
}

void solve()
{
    vector<int> cur;
    cnt[0] = n;
    foru(i, 1, n) if (deg[i] == 1) cur.pb(i);
    int i = 1;
    while (cur.size())
    {
        vector<int> list1;
        cnt[i] = cnt[i - 1] - cur.size();
        for (auto x : cur)
        {
            deg[x] = 0;
            for (auto v : adj[x])
            {
                deg[v]--;
                if (deg[v] == 1)
                    list1.pb(v);
            }
        }
        cur = list1;
        i++;
    }
    cout << cnt[k] << endl;
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