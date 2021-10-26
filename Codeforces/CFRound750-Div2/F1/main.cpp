
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
int n, m;
int mmax = 0;
const int maxVal = 5005;
vector<int> pos[maxVal];
const int maxBase = 8200;
int dp[maxVal][maxBase];
void read()
{
    mmax = 0;
    cin >> n;
    foru(i, 1, n)
    {
        int x;
        cin >> x;
        pos[x].pb(i);
    }
}

void solve()
{
    int MXOR = 8191;
    memset(dp, 60, sizeof(dp));
    dp[0][0] = 0;
    foru(i, 1, 5000)
    {
        foru(j, 0, MXOR) dp[i][j] = min(dp[i - 1][j], dp[i][j]);
        if (pos[i].size() == 0)
            continue;
        foru(j, 0, MXOR)
        {
            int val = (j ^ i);
            int x = dp[i - 1][val];
            if (x > n)
                continue;
            int pp = upper_bound(all(pos[i]), x) - pos[i].begin();
            if (pp == pos[i].size())
                continue;
            dp[i][j] = min(dp[i][j], pos[i][pp]);
        }
    }
    vector<int> ans;
    foru(i, 0, MXOR)
    {
        if (dp[5000][i] <= n)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << " ";
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
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}