
// binhdzai

#include <bits/stdc++.h>
#define maxn 200007
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
int l[maxn], r[maxn];
void read()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void solve()
{
    foru(i, 1, n)
    {
        l[i] = 1;
        if (a[i] < a[i - 1])
            l[i] = l[i - 1] + 1;
    }
    ford(i, n, 1)
    {
        r[i] = 1;
        if (a[i] < a[i + 1])
            r[i] = r[i + 1] + 1;
    }
    int top = 1, last = n;
    int cur = 0;
    int win = -1;
    int pr = -1;
    // cout << r[top] << " " << l[last] << endl;
    while (top <= last)
    {
        if (top == last)
        {
            win = cur;
            break;
        }
        if (a[top] == a[last])
        {
            if (r[top] % 2 != 0 || l[last] % 2 != 0)
                win = cur;
            else
                win = 1 - cur;
            break;
        }
        if (a[top] > a[last])
        {
            if (r[top] % 2)
            {
                win = cur;
                break;
            }
            if (a[last] <= pr)
            {
                win = 1 - cur;
                break;
            }
            pr = a[last--];
        }
        else
        {
            if (l[last] % 2)
            {

                win = cur;
                break;
            }
            if (a[top] <= pr)
            {
                win = 1 - cur;
                break;
            }
            pr = a[top++];
        }
        cur = 1 - cur;
    }
    if (win == 0)
    {
        cout << "Alice";
    }
    else
        cout << "Bob";
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