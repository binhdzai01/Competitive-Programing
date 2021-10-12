
// binhdzai

#include <bits/stdc++.h>
#define maxn 4007
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
bool dp[maxn][maxn];
void read()
{
    cin >> n;
    n *= 2;
    foru(i, 1, n) cin >> a[i];
    a[n + 1] = n + 1;
}
vector<int> v;
void solve()
{
    v.clear();
    int i = 1;
    while (i <= n)
    {
        int j = i + 1;
        while (a[i] > a[j])
            j++;
        v.push_back(j - i);
        i = j;
    }
    int sz = v.size();
    foru(i, 0, sz) foru(j, 0, n / 2) dp[i][j] = false;
    dp[0][0] = true;
    foru(i, 1, sz)
    {
        foru(j, 0, n / 2)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1] && dp[i - 1][j - v[i - 1]] == true)
            {
                dp[i][j] = true;
            }
        }
    }
    cout << ((dp[sz][n / 2] == true) ? "YES\n" : "NO\n");
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