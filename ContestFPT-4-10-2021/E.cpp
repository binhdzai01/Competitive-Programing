
// binhdzai

#include <bits/stdc++.h>
#define maxn 105
#define ft first
#define sd second
#define all(v) (v.begin(), v.end())
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int n, k, a[maxn];
int c[maxn][maxn];
int mmax = 0;
void read()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mmax = max(mmax, a[i]);
        for (int j = 1; j <= a[i]; ++j)
        {
            cin >> c[i][j];
        }
    }
}

void solve()
{
    int pr = 0;
    int index = 1;
    while (k && index <= mmax && pr < 50)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (index > a[i])
            {
                pr += 50;
                k--;
                break;
            }
            if (c[i][index] < pr)
                continue;
            pr += c[i][index];
            // cout << pr << endl;
            k--;
            if (k == 0)
                break;
        }
        index++;
    }
    cout << pr + k * 50;
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