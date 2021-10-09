#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
#define all(a) a.begin(), a.end()
#define pb push_back
#define N 200000
#define ii pair<int, int>
#define se second
#define fi first
#define bit(i) (i & (-i))
#define base 29
#define mod 1000000007ll

int o1[4] = {0, 1, 0, -1};
int o2[4] = {-1, 0, 1, 0};

string yno[2] = {"NO\n", "YES\n"};

void print(vector<int> &a)
{
    for (int i : a)
        cout << i << ' ';
    cout << endl;
}

void print(ii a)
{
    cout << a.first << ' ' << a.second << endl;
}

void print(int a[], int n)
{
    rep(i, 1, n) cout << a[i] << ' ';
    cout << endl;
}

int n, m, a[1005][1005];
bool b[1005][1005];

bool check(int u, int v)
{
    return ((1 <= u && u <= n) && (1 <= v && v <= m));
}

int dfs(int u, int v)
{
    b[u][v] = true;
    int ans = 1;
    rep(i, 0, 3)
    {
        if ((a[u][v] >> i) & 1)
            continue;
        int x = u + o1[i];
        int y = v + o2[i];
        if (!check(x, y) || b[x][y])
            continue;
        ans += dfs(x, y);
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            cin >> a[i][j];
        }
    }
    vector<int> ans;
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            if (!b[i][j])
            {
                ans.push_back(dfs(i, j));
            }
        }
    }
    sort(all(ans), greater<int>());
    for (int i : ans)
        cout << i << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("Test.inp", "r", stdin);
    //freopen("Test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
