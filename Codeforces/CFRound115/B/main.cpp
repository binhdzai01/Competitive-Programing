
// binhdzai

#include <bits/stdc++.h>
#define maxn 1007
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
int n, m, a[maxn][6];

void read()
{
    cin >> n;
    foru(i, 1, n)
    {
        foru(j, 1, 5) cin >> a[i][j];
    }
}

void solve()
{
    foru(x, 1, 5)
    {
        foru(y, x + 1, 5)
        {
            int cntX = 0;
            int cntY = 0;
            int cntBoth = 0;
            foru(i, 1, n)
            {
                if (a[i][x] == 1 && a[i][y] == 1)
                {
                    cntBoth++;
                }
                else
                {
                    if (a[i][x] == 1)
                        cntX++;
                    if (a[i][y] == 1)
                        cntY++;
                }
                if (cntX <= (n / 2) && cntY <= (n / 2) && (cntX + cntY + cntBoth) == n)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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