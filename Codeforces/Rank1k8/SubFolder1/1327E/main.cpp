
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
int n, m, a[maxn];
const int mod = 998244353;
int p[maxn];
void read()
{
    cin >> n;
    p[0] = 1;
    foru(i, 1, n)
    {
        p[i] = p[i - 1] * 10 % mod;
    }
}

void solve()
{
    foru(i, 1, n - 1)
    {
        int res = 2 * 10 * 9 * p[n - i - 1];
        res += (n - i - 1) * 10 * 9 * 9 * p[n - i - 2];
        res = res % mod;
        cout << res << endl;
    }
    cout << 10 << endl;
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