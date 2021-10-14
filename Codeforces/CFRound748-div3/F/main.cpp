
// binhdzai

#include <bits/stdc++.h>
#define maxn 44
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
int n, a, b;
bool dp[maxn][maxn][maxn][maxn];
string s;
void read()
{
    cin >> n >> a >> b;
    cin >> s;
    s = ' ' + s;
}

void solve()
{
    memset(dp, false, sizeof(dp));
    dp[0][0][0][0] = true;
    foru(i, 1, n)
    {
        foru(j, 0, i)
        {
            foru(x, 0, a - 1)
            {
                foru(y, 0, b - 1)
                {
                    int val = s[i] - '0';
                    if (dp[i - 1][j][x][y] == true)
                        dp[i][j][x][(y * 10 + val) % b] = true;
                    if (j > 0 && dp[i - 1][j - 1][x][y] == true)
                        dp[i][j][(x * 10 + val) % a][y] = true;
                }
            }
        }
    }
    int ans = 1e9;
    int m;
    foru(i, 1, n - 1)
    {
        if (dp[n][i][0][0] == true)
        {
            if (ans > abs(i * 2 - n))
            {
                m = i;
                ans = abs(i * 2 - n);
            }
        }
    }
    if (ans == 1e9)
    {
        cout << -1 << endl;
        return;
    }
    int x = 0, y = 0;
    string res = "";
    int cnt = 100;
    while (n > 0 && cnt--)
    {
        int val = s[n] - '0';
        foru(i, 0, a)
        {
            if ((i * 10 + val) % a == x)
            {
                int preX = i;
                if (m > 0 && dp[n - 1][m - 1][preX][y] == true)
                {
                    n--;
                    m--;
                    x = preX;
                    res = res + 'R';
                    goto endd;
                }
            }
        }
        foru(i, 0, b)
        {
            if ((i * 10 + val) % b == y)
            {
                int preY = i;
                if (dp[n - 1][m][x][preY] == true)
                {
                    n--;
                    y = preY;
                    res = res + 'B';
                    goto endd;
                }
            }
        }
    endd:;
    }
    reverse(all(res));
    cout << res << endl;
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