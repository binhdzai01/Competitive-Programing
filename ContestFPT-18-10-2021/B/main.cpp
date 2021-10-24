
// binhdzai

#include <bits/stdc++.h>
#define maxn 500007
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
int n, m, cnt;
string s;
pair<int, int> w[maxn];
void read()
{
    cin >> s;
    n = s.size();
    s = ' ' + s;
}

void solve()
{
    int cur = 0;
    for (int i = 1; i < n; ++i)
    {
        cur++;
        if (s[i] != s[i + 1])
        {
            w[++cnt] = {s[i], cur};
            cur = 0;
        }
    }
    cur++;
    w[++cnt] = {s[n], cur};
    if (cnt % 2 == 1)
    {
        int mid = (cnt + 1) / 2;
        if (w[mid].sd >= 2)
        {
            bool ok = true;
            foru(i, 1, mid - 1)
            {
                if (w[mid - i].ft != w[mid + i].ft || w[mid - i].sd + w[mid + i].sd < 3)
                    ok = false;
            }
            if (ok == true)
            {
                cout << w[mid].sd + 1;
                return;
            }
        }
    }
    cout << 0;
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