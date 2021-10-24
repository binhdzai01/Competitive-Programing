
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
int sum = 0;
void read()
{
    sum = 0;
    cin >> n;
    foru(i, 1, n) cin >> a[i], sum += a[i];
}

void solve()
{
    foru(i, 2, sqrt(sum))
    {
        if (sum % i == 0)
        {
            cout << n << endl;
            foru(i, 1, n) cout << i << " ";
            cout << endl;
            return;
        }
    }
    foru(i, 1, n)
    {
        if (a[i] % 2)
        {
            cout << n - 1 << endl;
            foru(j, 1, n)
            {
                if (i != j)
                    cout << j << " ";
            }
            cout << endl;
            return;
        }
    }
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