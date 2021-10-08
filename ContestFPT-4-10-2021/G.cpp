
// binhdzai

#include <bits/stdc++.h>
#define maxn 1000007
#define ft first
#define sd second
#define all(v) (v.begin(), v.end())
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
int n, m, a[maxn], b[maxn];
int cnt[maxn];
int ka, kb;
typedef pair<int, int> ii;
void read()
{
    cin >> n >> m >> ka >> kb;
    for (int i = 1; i <= ka; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= kb; ++i)
    {
        cin >> b[i];
        cnt[b[i]]++;
    }
    if (ka > m - 1 or kb > n - 1)
    {
        cout << "No\n";
        exit(0);
    }
}

void solve()
{
    multiset<int> pqa, pqb;
    for (int i = 1; i <= n; ++i)
    {
        if (!cnt[i])
            pqa.insert(i);
    }
    for (int i = n + 1; i <= n + m; ++i)
    {
        if (!cnt[i])
            pqb.insert(i);
    }

    set<ii> edges;
    int x = 1, y = 1;
    while (true)
    {
        if (pqa.size() and y <= kb)
        {
            edges.insert({*pqa.begin(), b[y]});
            pqa.erase(pqa.begin());
            cnt[b[y]]--;
            if (cnt[b[y]] == 0)
            {
                pqb.insert(b[y]);
            }
            y++;
        }
        else if (pqb.size() and x <= ka)
        {
            edges.insert({*pqb.begin(), a[x]});
            pqb.erase(pqb.begin());
            cnt[a[x]]--;
            if (cnt[a[x]] == 0)
            {
                pqa.insert(a[x]);
            }
            x++;
        }
        else if (pqa.size() + pqb.size() > 1)
        {
            edges.insert({*pqa.begin(), *pqb.begin()});
            if (pqa.size() > pqb.size())
            {
                pqa.erase(pqa.begin());
            }
            else
            {
                pqb.erase(pqb.begin());
            }
        }
        else
        {
            break;
        }
    }
    cout << "Yes\n";
    while (edges.size())
    {
        auto it = *edges.begin();
        cout << it.first << " " << it.second << "\n";
        edges.erase(it);
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