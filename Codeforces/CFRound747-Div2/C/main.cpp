
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
int n;
char c;
string s;
void read()
{
    cin >> n >> c;
    cin >> s;
    s = ' ' + s;
}

bool check(int x)
{
    int cur = x;
    while (cur <= n)
    {
        if (s[cur] != c)
            return false;
        cur += x;
    }
    return true;
}
void solve()
{
    bool zeros = true;
    foru(i, 1, n)
    {
        if (s[i] != c)
            zeros = false;
    }
    if (zeros)
    {
        cout << 0 << endl;
        return;
    }
    foru(i, 2, n)
    {
        if (check(i))
        {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n - 1 << " " << n << endl;
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