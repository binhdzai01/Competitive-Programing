
// binhdzai

#include <bits/stdc++.h>
#define maxn 10000007
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define int long long
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
int n, m, a[maxn];
void read()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}

void solve()
{
    if (count(a, a + n, a[0]) == n)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }

    if (n % 2 == 0)
    {
        cout << 2 << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << i % 2 + 1 << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == a[(i + 1) % n])
        {
            vector<int> ans(n);
            for (int j = 0, pos = i + 1; pos < n; ++pos, j ^= 1)
            {
                ans[pos] = j + 1;
            }
            for (int j = 0, pos = i; pos >= 0; --pos, j ^= 1)
            {
                ans[pos] = j + 1;
            }
            cout << 2 << endl;
            for (int pos = 0; pos < n; ++pos)
            {
                cout << ans[pos] << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << 3 << endl;
    for (int i = 0; i < n - 1; ++i)
    {
        cout << i % 2 + 1 << " ";
    }
    cout << 3 << endl;
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    int test;
    cin >> test;
    while (test--)
    {
        read();
        solve();
    }
    return 0;
}