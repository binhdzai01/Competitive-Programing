
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
int n, m, a[maxn];
bool avRow[maxn];
bool avCol[maxn];
int sumRow, cntCol;
int sumCol, cntRow;
void read()
{
    cin >> n >> m;
    sumRow = sumCol = n * (n + 1) / 2;
    memset(avRow, true, sizeof(avRow));
    memset(avCol, true, sizeof(avCol));
    cntRow = cntCol = n;
}

void solve()
{
    while (m--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'R')
        {
            if (!avRow[x])
            {
                cout << 0 << endl;
            }
            else
            {
                cout << cntCol * x + sumCol << endl;
                avRow[x] = false;
                sumRow -= x;
                cntRow--;
            }
        }
        else
        {
            if (!avCol[x])
            {
                cout << 0 << endl;
            }
            else
            {
                cout << cntRow * x + sumRow << endl;
                avCol[x] = false;
                sumCol -= x;
                cntCol--;
            }
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
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}