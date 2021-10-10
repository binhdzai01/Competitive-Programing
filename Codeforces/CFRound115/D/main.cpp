
// binhdzai

#include <bits/stdc++.h>
#define maxn 200007
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
int cntA[maxn], cntB[maxn];
typedef pair<int, int> ii;
ii a[maxn];
int sum;
vector<ii> lst;
void read()
{
    cin >> n;
    lst.clear();
    foru(i, 1, n) cntA[i] = cntB[i] = 0;
    foru(i, 1, n)
    {
        cin >> a[i].ft >> a[i].sd;
        cntA[a[i].ft]++;
        cntB[a[i].sd]++;
        lst.emplace_back(a[i].ft, a[i].sd);
    }
}
int dp[maxn][4];
void clear()
{
    foru(i, 1, n)
    {
        foru(j, 1, 3)
        {
            dp[i][j] = 0;
        }
    }
}
int C2(int n)
{
    return n * (n - 1) / 2;
}
int C3(int n)
{
    return n * (n - 1) * (n - 2) / 6;
}
void solve()
{
    int ans = 0;
    clear();
    foru(i, 0, n) dp[i][0] = 1;
    foru(i, 1, n)
    {
        foru(j, 1, 3)
        {

            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * cntA[i];
        }
    }
    ans += dp[n][3];
    clear();
    foru(i, 1, n)
    {
        foru(j, 1, 3)
        {

            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * cntB[i];
        }
    }
    ans += dp[n][3];

    int res = C3(n);
    foru(i, 1, n)
    {
        int x = cntA[i];
        res -= C2(x) * (n - x);
        res -= C3(x);

        x = cntB[i];
        res -= C2(x) * (n - x);
        res -= C3(x);
    }

    for (auto x : lst)
    {
        res += (cntA[x.ft] - 1) * (cntB[x.sd] - 1);
    }
    cout << ans - res << endl;
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