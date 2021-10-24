
// binhdzai

#include <bits/stdc++.h>
#define maxn 1005
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define int unsigned long long
#define foru(i, a, b) for (int i = a; i <= b; ++i)
#define ford(i, a, b) for (int i = a; i >= b; --i)
#define endl "\n";
using namespace std;
int n, m;
int w;
bool st[maxn], fn[maxn];
pair<int, int> a[maxn];
void read()
{
    cin >> w >> n;
    foru(i, 1, n)
    {
        cin >> a[i].sd >> a[i].ft;
    }
}

int distance(int i, int j)
{
    if (j == n + 1)
        return a[i].sd * a[i].sd;
    if (j == 0)
        return (w - a[i].sd) * (w - a[i].sd);
    return (a[i].ft - a[j].ft) * (a[i].ft - a[j].ft) + (a[i].sd - a[j].sd) * (a[i].sd - a[j].sd);
}

bool check(int dis)
{
    memset(st, false, sizeof(st));
    memset(fn, false, sizeof(fn));
    queue<int> q;
    foru(i, 1, n)
    {
        if (distance(i, n + 1) <= dis)
        {
            q.push(i);
            st[i] = true;
        }
    }

    while (q.size())
    {
        int u = q.front();
        q.pop();
        foru(v, 1, n)
        {
            if (st[v] == false && distance(u, v) <= dis)
            {
                st[v] = true;
                q.push(v);
            }
        }
    }
    foru(i, 1, n)
    {
        if (distance(i, 0) <= dis)
        {
            q.push(i);
            fn[i] = true;
        }
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        foru(v, 1, n)
        {
            if (fn[v] == false && distance(u, v) <= dis)
            {
                fn[v] = true;
                q.push(v);
            }
        }
    }
    foru(i, 1, n)
    {
        foru(j, 1, n)
        {
            if (i == j || st[i] == false || fn[j] == false)
                continue;
            if (distance(i, j) <= dis * 4)
            {
                return true;
            }
        }
    }
    return false;
}

void display(int dis)
{
    memset(st, false, sizeof(st));
    memset(fn, false, sizeof(fn));
    queue<int> q;
    foru(i, 1, n)
    {
        if (distance(i, -1) <= dis)
        {
            q.push(i);
            st[i] = true;
        }
    }

    while (q.size())
    {
        int u = q.front();
        q.pop();
        foru(v, 1, n)
        {
            if (st[v] == false && distance(u, v) <= dis)
            {
                st[v] = true;
                q.push(v);
            }
        }
    }
    foru(i, 1, n)
    {
        if (distance(i, 0) <= dis)
        {
            q.push(i);
            fn[i] = true;
        }
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        foru(v, 1, n)
        {
            if (fn[v] == false && distance(u, v) <= dis)
            {
                fn[v] = true;
                q.push(v);
            }
        }
    }
    foru(i, 1, n)
    {
        foru(j, 1, n)
        {
            if (i == j || st[i] == false || fn[j] == false)
                continue;
            if (distance(i, j) <= dis * 4)
            {
                cout << fixed << setprecision(1) << (double)(a[i].sd + a[j].sd) / 2 << " " << (double)(a[i].ft + a[j].ft) / 2;
                return;
            }
        }
    }
}

void solve()
{
    int l = 0, r = 4e18;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(mid) == true)
            r = mid;
        else
            l = mid;
    }
    // cout << r << endl;
    display(r);
}
#undef int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
        solve();
    }
    return 0;
}