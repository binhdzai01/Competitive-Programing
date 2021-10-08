
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
using namespace std;
int n, m, a[maxn];
int sum = 0, maxm = 0;
void read()
{
    cin >> a[1] >> a[2] >> a[3];
    foru(i, 1, 3)
    {
        sum += a[i];
        maxm = max(a[i], maxm);
    }
}

void solve()
{
    cout << min(sum / 3, sum - maxm);
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