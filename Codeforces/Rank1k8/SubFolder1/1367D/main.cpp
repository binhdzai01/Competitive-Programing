
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
int n, m, a[maxn];
int cnt[27];
string s;
vector<pair<char, int>> v;
char c[maxn];
void read()
{
    v.clear();
    cin >> s;
    foru(i, 0, 26) cnt[i] = 0;
    foru(i, 0, s.size() - 1)
    {
        cnt[s[i] - 'a']++;
    }
    cin >> n;
    foru(i, 1, n) cin >> a[i];
}
bool compare(pair<char, int> a1, pair<char, int> a2)
{
    return a1.ft > a2.ft;
}
vector<int> cur, list1;
void solve()
{
    cur.clear();
    foru(i, 0, 26) v.emplace_back(i, cnt[i]);
    sort(all(v), compare);
    int index = 0;
    foru(i, 1, n)
    {
        if (a[i] == 0)
            cur.pb(i);
    }

    while (cur.size())
    {
        list1.clear();
        for (auto x : cur)
            list1.push_back(x);
        cur.clear();
        int sz = list1.size();
        while (v[index].sd < sz)
            index++;
        for (auto x : list1)
            c[x] = char(v[index].ft + 'a');
        index++;
        foru(i, 1, n)
        {
            if (a[i] == 0)
                continue;
            for (auto x : list1)
            {
                a[i] -= (abs(i - x));
            }
            if (a[i] == 0)
                cur.pb(i);
        }
    }
    foru(i, 1, n) cout << c[i];
    cout << endl;
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