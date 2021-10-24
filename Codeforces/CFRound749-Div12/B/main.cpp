
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
int n, m, a[maxn], q;
string c[maxn];
int cnt[maxn];
bool av[maxn];
void read()
{
    cin >> n >> m;
    foru(i, 1, n)
    {
        cin >> c[i];
        c[i] = ' ' + c[i];
    }
    foru(i, 1, m) cnt[i] = 1;
    memset(av, true, sizeof(av));
    foru(i, 2, m)
    {
        foru(j, 1, n)
        {
            av[j] = false;
            if (c[j][i] == '.' || av[j - 1])
                av[j] = true;
            if (c[j][i] == 'X')
            {
                av[j] = false;
            }
            if (av[j - 1] == false && c[j][i - 1] == 'X')
            {
                cnt[i] = 0;
            }
        }
    }
    foru(j, 2, m)
    {
        cnt[j] += cnt[j - 1];
    }
}

void solve()
{
    int q;
    cin >> q;
    foru(i, 1, q)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "YES\n";
            continue;
        }
        cout << ((cnt[b] - cnt[a] == b - a) ? "YES\n" : "NO\n");
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
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}