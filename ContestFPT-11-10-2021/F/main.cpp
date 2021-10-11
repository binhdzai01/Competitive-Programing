
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
void read()
{
    cin >> n;
}

void solve()
{
    int m = n;

    int p = -1;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            p = i;
            m /= i;
            while (m % i == 0)
            {
                p *= i;
                m /= i;
            }
            break;
        }
    }

    if (p == -1 || p == n)
    {
        cout << "NO";
        return;
    }

    int q = n / p;
    if (p < q)
    {
        swap(p, q);
    }
    for (int i = 1; i < n / p; ++i)
    {
        if ((n - p * i - 1) % q == 0)
        {
            cout << "YES\n";
            cout << 2 << '\n';
            cout << i << ' ' << n / p << '\n';
            cout << (n - p * i - 1) / q << ' ' << n / q << '\n';
            return;
        }
    }
    cout << "NO";
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