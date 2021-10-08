
// binhdzai

#include <bits/stdc++.h>
#define maxn 1005
#define ft first
#define sd second
#define all(v) (v.begin(), v.end())
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int n, m, a[maxn];
int cnt[maxn];
vector<int> v;
int countMagic = 0;
void read()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            cnt[a[i]]++;
        }
        if (a[i] == 0)
        {
            countMagic++;
        }
        if (a[i] < 0)
        {
            if (cnt[-a[i]] == 0 && countMagic == 0)
            {
                cout << "NO";
                exit(0);
            }
            if (cnt[-a[i]] > 0)
                cnt[-a[i]]--;
            else
            {
                v.push_back(-a[i]);
                countMagic--;
            }
        }
    }
}

void solve()
{
    while (countMagic > 0)
    {
        v.push_back(1);
        countMagic--;
    }
    cout << "YES\n";
    for (auto x : v)
    {
        cout << x << " ";
    }
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}