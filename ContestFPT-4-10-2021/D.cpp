
// binhdzai

#include <bits/stdc++.h>
#define maxn 100007
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int n, m, a[maxn], d;
double f[maxn][10];
int trace[maxn][10];
void read()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
}

void solve()
{
    memset(f, -60, sizeof(f));
    memset(trace, -1, sizeof(trace));
    f[0][1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 10; ++j)
            f[i][j] = f[i - 1][j];
        for (int j = 0; j < 10; ++j)
        {
            int val = a[i] * j % 10;
            if (f[i][val] < f[i - 1][j] + log2(a[i]))
            {
                f[i][val] = f[i - 1][j] + log2(a[i]);
                trace[i][val] = j;
            }
        }
    }
    if (f[n][d] <= 0)
    {
        cout << -1;
        return;
    }
    vector<int> kq;
    for (int i = n; i >= 1; --i)
    {
        if (trace[i][d] != -1)
        {
            kq.push_back(a[i]);
            d = trace[i][d];
        }
    }
    sort(all(kq));
    cout << kq.size() << endl;
    for (auto x : kq)
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}