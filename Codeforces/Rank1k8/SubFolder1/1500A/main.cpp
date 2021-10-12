
// binhdzai

#include <bits/stdc++.h>
#define maxn 5000007
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
int x[maxn], y[maxn];
void read()
{
    cin >> n;
    foru(i, 1, n) cin >> a[i];
}

void solve()
{
    foru(i, 1, n)
    {
        foru(j, i + 1, n)
        {
            int res = a[i] + a[j];
            if (x[res] && x[res] != i && y[res] != j && x[res] != j && y[res] != i)
            {
                cout << "YES\n";
                cout << i << " " << j << " " << x[res] << " " << y[res];
                return;
            }
            x[res] = i;
            y[res] = j;
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