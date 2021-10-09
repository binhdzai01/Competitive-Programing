
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
int n, m, a[maxn];
double p;
int c[4][maxn];
void init()
{
    foru(i, 0, n)
    {
        c[0][i] = 1;
    }
    foru(i, 1, 3)
    {
        foru(j, 1, n)
        {
            c[i][j] = c[i][j - 1] + c[i - 1][j - 1];
        }
    }
}
void read()
{
    cin >> n >> p;
    init();
}

void solve()
{
    ford(i, n, 0)
    {
        double x = c[3][i]*1 + c[2][i]*c[1][n-i]*1 + c[1][i]*c[2][n-i]*0.5;
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