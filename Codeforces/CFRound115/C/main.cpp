
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
int sum;
void read()
{
    sum = 0;
    cin >> n;
    foru(i, 1, n)
    {
        cin >> a[i];
        sum += a[i];
    }
}

void solve()
{
    map<int, int> M;
    foru(i, 1, n)
    {
        a[i] = a[i] * n - sum;
    }
    int cntZeros = 0;
    int ans = 0;
    foru(i, 1, n)
    {
        if (a[i] == 0)
            cntZeros++;
        else
        {
            ans += M[-a[i]];
            M[a[i]]++;
        }
    }
    ans += cntZeros * (cntZeros - 1) / 2;
    cout << ans << endl;
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