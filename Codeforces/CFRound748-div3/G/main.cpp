
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
string s;
int psum[maxn];
void read()
{
    cin >> s;
}
void solve()
{
    foru(i, 0, s.size() - 1)
    {
        psum[i + 1] = psum[i];
        if (s[i] == '(' || s[i] == ')')
            continue;
        if (i % 2)
            psum[i + 1]++;
        else
            psum[i + 1]--;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int val = psum[r] - psum[l - 1];
        cout << abs(val) << '\n';
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
    int test;
    cin >> test;
    while (test--)
    {
        read();
        solve();
    }
    return 0;
}