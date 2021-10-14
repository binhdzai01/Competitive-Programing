
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
    cin >> s;
    n = s.size();
    reverse(all(s));
}

void solve()
{
    s = ' ' + s;
    int isFive = 0, isZero = 0;
    foru(i, 1, n)
    {
        if (s[i] == '5')
        {
            if (isZero == 1)
            {
                cout << i - 2 << endl;
                return;
            }
            isFive = 1;
        }
        if (s[i] == '0')
        {
            if (isZero == 1)
            {
                cout << i - 2 << endl;
                return;
            }
            isZero = 1;
        }
        if ((s[i] == '2' || s[i] == '7') && isFive == 1)
        {
            cout << i - 2 << endl;
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