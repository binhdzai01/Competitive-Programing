
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
const int mod = 1e9 + 7;
int power(int a, int b)
{
    int res = 1;
    for (int i = a; b > 0; i = i * i % mod)
    {
        if (b % 2)
            res = res * i % mod;
        b /= 2;
    }
    return res;
}
void read()
{
    cin >> n >> m;
}

int getbit(int x, int i)
{
    return (x >> i) & 1;
}
void solve()
{
    int res = 0;
    for (int i = 0; i <= 31; ++i)
    {
        if (getbit(m, i) == 1)
            res = (res + power(n, i)) % mod;
    }
    cout << res << endl;
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