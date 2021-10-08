
// binhdzai

#include <bits/stdc++.h>
#define maxn 10000007
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
int n, m, k;
void read()
{
    cin >> n >> m >> k;
}

bool check(int mid)
{
    int cur = 0;
    for (int i = 1; i <= min(n, mid); ++i)
    {
        cur += min(m, mid / i);
    }
    return cur >= k;
}

void solve()
{
    int l = 0, r = m * n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(mid) == true)
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}