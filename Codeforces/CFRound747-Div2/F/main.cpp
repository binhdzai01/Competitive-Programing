
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
int n, k, s;
void read()
{
    cin >> s >> n >> k;
}

void solve()
{
    if (s == k)
    {
        cout << "YES" << endl;
        return;
    }
    if (s < k)
    {
        cout << "NO" << endl;
        return;
    }
    int posa = s + k;
    int l = s - k + 1;
    int r = s;
    int siz = r - l + 1;
    int a = 0, b = 0;
    int num = (s / k) * k;
    b = r - num + 1;
    a = siz - b;
    if ((s / k) % 2 == 1)
        posa -= b;
    else
        posa -= a;
    if ((2 * n + 1) > posa)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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