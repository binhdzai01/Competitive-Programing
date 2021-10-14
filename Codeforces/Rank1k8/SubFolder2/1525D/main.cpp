
// binhdzai

#include <bits/stdc++.h>
#define maxn 5005
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
vector<int> v;
int f[maxn][maxn];
void read()
{
    cin >> n;
    foru(i, 1, n)
    {
        cin >> a[i];
        if (a[i] == 1)
            v.pb(i);
    }
}

void solve()
{
    int sz = v.size();
    memset(f, 60, sizeof(f));
    f[0][0] = 0;
    foru(i, 1, n)
    {
        foru(j, 0, sz)
        {
            f[i][j] = f[i - 1][j];
            if (j > 0 && !a[i])
            {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + abs(v[j - 1] - i));
            }
        }
    }
    cout << f[n][sz];
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