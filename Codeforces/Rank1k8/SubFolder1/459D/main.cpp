
// binhdzai

#include <bits/stdc++.h>
#define maxn 1000007
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
map<int, int> M;
int l[maxn], r[maxn], d[maxn];
struct bit
{
    int d[maxn];
    void update(int x)
    {
        for (; x < maxn; x += (x & -x))
            d[x]++;
    }
    int get(int x)
    {
        int res = 0;
        for (; x > 0; x -= (x & -x))
            res += d[x];
        return res;
    }
} B;
void read()
{
    cin >> n;
    foru(i, 1, n) cin >> a[i];
}

void solve()
{
    int ans = 0;
    foru(i, 1, n)
    {

        l[i] = ++M[a[i]];
    }
    M.clear();
    ford(i, n, 1)
    {
        r[i] = ++M[a[i]];
        ans += B.get(l[i] - 1);
        B.update(r[i]);
    }
    cout << ans << endl;
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