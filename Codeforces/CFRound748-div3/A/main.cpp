
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
int a[maxn];
int mmax;
void read()
{
    mmax = 0;
    foru(i, 1, 3)
    {
        cin >> a[i];
        mmax = max(mmax, a[i]);
    }
}

void solve()
{
    int cnt = 0;
    foru(i, 1, 3) cnt += (mmax == a[i]);
    foru(i, 1, 3)
    {
        cout << mmax - a[i] + 1 - (a[i] == mmax && cnt == 1) << " ";
    }
    cout << endl;
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