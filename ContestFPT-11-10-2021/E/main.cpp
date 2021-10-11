
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
void pr(int x, int y)
{
    cout << char(x - 1 + 'a') << y << " ";
}
void read()
{
    cin >> n;
}

void travel(int x)
{
    if (x % 2)
        foru(i, 1, 8)
        {
            pr(i, x);
        }
    else
        ford(i, 8, 1)
        {
            pr(i, x);
        }
}

void solve()
{
    if (n <= 56)
    {
        int x = 1, y = 1;
        pr(x, y);
        foru(i, 1, n - 2)
        {
            if (x % 2 == 0)
            {
                if (y == 1)
                    x++;
                else
                    y--;
            }
            else
            {
                if (y == 8)
                    x++;
                else
                    y++;
            }
            pr(x, y);
        }
        if (y == 8)
        {
            x++;
        }
        else
        {
            if (x % 2 == 0)
                x = 8;
            else
                y = 8;
        }
        pr(x, y);
        pr(8, 8);
    }
    else
    {
        foru(i, 1, 6) travel(i);
        cout << "a7 h7 g7 f7 e7 d7 c7 b7 b8 ";
        if (n == 57)
            cout << "h8";
        if (n == 58)
            cout << "c8 h8";
        if (n == 59)
            cout << "c8 d8 h8";
        if (n == 60)
            cout << "c8 d8 e8 h8";
        if (n == 61)
            cout << "c8 d8 e8 f8 h8";
        if (n == 62)
            cout << "c8 d8 e8 f8 g8 h8";
        if (n == 63)
            cout << "a8 c8 d8 e8 f8 g8 h8";
    }
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("./../input.txt", "r", stdin);
    // freopen("./../output.txt", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}