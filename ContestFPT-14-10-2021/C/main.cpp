
// binhdzai

#include <bits/stdc++.h>
#define maxn 10
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
int c[maxn][maxn];
int k, sz;
void read()
{
    cin >> n >> k;
    sz = n * (n - 1) / 2;
}
int getbit(int x, int i)
{
    return (x >> i) & 1;
}
bool check(int x)
{

    foru(i, 0, sz - 1)
    {
        a[i] = getbit(x, i);
    }
    int cnt = 0;
    foru(i, 1, n)
    {
        foru(j, i + 1, n)
        {
            c[i][j] = a[cnt++];
            c[j][i] = !c[i][j];
        }
    }
    int ans = 0;
    foru(i, 1, n)
    {
        int cur = 0;
        foru(j, 1, n) cur += c[i][j];
        ans += cur * cur;
    }
    if (ans == k)
    {
        foru(i, 1, n)
        {
            foru(j, 1, n)
            {
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    return (ans == k);
}

void solve()
{
    foru(x, 0, (1 << sz) - 1)
    {
        if (check(x))
            return;
    }
    cout << -1 << endl;
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