
// binhdzai

#include <bits/stdc++.h>
#define maxn 200007
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define endl "\n";
using namespace std;
int n, m, a[maxn];
int cnt[maxn][202];
vector<int> pos[202];

void read()
{
    cin >> n;
    foru(i, 1, 200) pos[i].clear();
    foru(i, 1, n)
    {
        foru(j, 1, 200) cnt[i][j] = cnt[i - 1][j];
        cin >> a[i];
        cnt[i][a[i]]++;
        pos[a[i]].pb(i);
    }
}

void solve()
{
    int ans = 0;
    foru(x, 1, 200)
    {
        ans = max(ans, (int)pos[x].size());
        foru(i, 0, (int)pos[x].size() / 2 - 1)
        {
            int l = pos[x][i], r = pos[x][pos[x].size() - 1 - i];
            foru(y, 1, 200)
            {
                ans = max(ans, (i + 1) * 2 + cnt[r - 1][y] - cnt[l][y]);
            }
        }
    }
    cout << ans << endl;
}
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