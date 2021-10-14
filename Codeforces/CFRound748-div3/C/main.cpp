
// binhdzai

#include <bits/stdc++.h>
#define maxn 400007
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
int sum[maxn];
string s;
void read()
{
    cin >> m >> n;
    foru(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
}
bool check(int mid)
{
    int cur = mid * m - sum[n - mid + 1];
    return cur <= m - 1;
}
void solve()
{
    sum[n + 1] = 0;
    ford(i, n, 1) sum[i] = sum[i + 1] + a[i];
    int l = 0, r = n + 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
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