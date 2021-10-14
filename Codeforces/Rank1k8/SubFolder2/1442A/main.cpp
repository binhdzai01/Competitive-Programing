
// binhdzai

#include <bits/stdc++.h>
#define maxn 30007
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
int n, m, a, b, p;
void read()
{
}

void solve()
{
    cin >> n >> a;
    p = a;
    foru(i, 2, n)
    {
        cin >> b;
        if (a > b)
            p -= a - b;
        a = b;
    }
    cout << (p < 0 ? "NO\n" : "YES\n");
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