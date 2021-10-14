
// binhdzai

#include <bits/stdc++.h>
#define maxn 2000007
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define endl "\n";
using namespace std;
int n, m, a[maxn], b[maxn];
int cnt[maxn], mmax, mmin;
void read()
{
    cin >> n;
    mmax = -1e6, mmin = 1e6;
    foru(i, 1, n)
    {
        cin >> a[i];
        mmax = max(mmax, a[i]);
        mmin = min(mmin, a[i]);
    }
    sort(a + 1, a + 1 + n);
}
vector<int> v;
vector<int> uoc;
void init()
{
    uoc.clear();
    sort(all(v));
    for (int x : v)
    {
        foru(i, 2, sqrt(x))
        {
            if (x % i == 0)
            {
                uoc.push_back(i);
                uoc.push_back(x / i);
            }
        }

        uoc.push_back(x);
    }
    uoc.push_back(1);
    sort(uoc.begin(), uoc.end());
    uoc.erase(unique(uoc.begin(), uoc.end()), uoc.end());
    reverse(all(uoc));
}
void solve()
{
    v.clear();
    foru(i, 1, n)
    {
        int x = upper_bound(a + 1, a + 1 + n, a[i]) - a;
        if (x - i >= n / 2)
        {
            cout << -1 << endl;
            return;
        }
    }
    foru(i, 1, n)
    {
        foru(j, i + 1, n)
        {
            if (a[i] != a[j])
                v.push_back(a[j] - a[i]);
        }
    }
    init();
    for (auto x : uoc)
    {
        bool ok = false;
        foru(i, 1, n)
        {
            int k = (a[i] % x + x) % x;
            cnt[k]++;
            if (cnt[k] >= n / 2)
                ok = true;
        }
        foru(i, 1, n)
        {
            int k = (a[i] % x + x) % x;
            cnt[k]--;
        }
        if (ok)
        {
            cout << x << endl;
            return;
        }
    }
}
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