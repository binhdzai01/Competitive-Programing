
// binhdzai

#include <bits/stdc++.h>
#define maxn 2007
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
int f[maxn][maxn];
void read()
{
    cin >> n;
    foru(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
}

int dp(int l, int r)
{
    if (f[l][r] != -1)
        return f[l][r];
    if (r - l <= 1)
    {
        f[l][r] = a[r] - a[l];
    }
    else
        f[l][r] = a[r] - a[l] + min(dp(l + 1, r), dp(l, r - 1));
    return f[l][r];
}

void solve()
{
    memset(f, -1, sizeof(f));
    cout << dp(1, n);
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