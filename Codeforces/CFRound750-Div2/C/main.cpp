
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
string s;
void read()
{
    cin >> n >> s;
    s = ' ' + s;
}
int res;
void ktra(char x)
{
    int l = 1, r = n;
    int count = 0;
    while (r > l)
    {
        while (s[l] != s[r] && (s[l] == x || s[r] == x))
        {
            if (s[l] == x)
                l++;
            else
                r--;
            count++;
        }
        if (s[l] != s[r])
            return;
        l++;
        r--;
    }
    res = min(res, count);
}

void solve()
{
    res = 1e9;
    for (char x = 'a'; x <= 'z'; ++x)
    {
        ktra(x);
    }
    cout << ((res == 1e9) ? -1 : res) << endl;
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