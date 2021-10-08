
// binhdzai

#include <bits/stdc++.h>
#define maxn 5002
#define ft first
#define sd second
#define all(v) (v.begin(), v.end())
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;
const double eps = 1e-7;
struct bit_double
{
    bit_double() {}
    bit_double(int n) : n(n)
    {
        a.assign(n + 1, 0);
    }
    void add(int i, double val)
    {
        for (; i >= 0; i = (i & (i + 1)) - 1)
        {
            a[i] += val;
        }
    }
    double find(int i)
    {
        double ret = 0;
        for (; i <= n; i |= i + 1)
            ret += a[i];
        return ret;
    }
    int n;
    vector<double> a;
};

struct bit_int
{
    bit_int() {}
    bit_int(int n) : n(n)
    {
        a.assign(n + 1, 0);
    }
    void add(int i, int val)
    {
        for (; i >= 0; i = (i & (i + 1)) - 1)
        {
            a[i] += val;
        }
    }
    int find(int i)
    {
        int ret = 0;
        for (; i <= n; i |= i + 1)
            ret += a[i];
        return ret;
    }
    int n;
    vector<int> a;
};

int n, w, h, m;
int bef[maxn][maxn * 2];
int aft[maxn][maxn * 2];
bit_int *cnt;
bit_double *sum_x;
bit_double *sum_y;

bool compare(double a, double b)
{
    return a < b && fabs(a - b) > eps;
}

bool check(int level)
{
    double sumx = sum_x->find(level + 1);
    double sumy = sum_y->find(level + 1);
    int count = cnt->find(level + 1);
    if (count == 0)
        return 1;
    int l = aft[level][0];
    int r = bef[level][n + 1];
    if (l > n)
        return 0;
    double ll = l - 0.5;
    double rr = r + 0.5;
    sumx /= count;
    sumy /= count;
    if (level % 2)
    {
        return compare(ll, sumy) && compare(sumy, rr);
    }
    else
    {
        return compare(ll, sumx) && compare(sumx, rr);
    }
}

void remove(int i, int j)
{
    bef[i][aft[i][j]] = bef[i][j];
    aft[i][bef[i][j]] = aft[i][j];
}

void read()
{
    cin >> n >> w >> h >> m;
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            bef[i][j] = j - 1;
            aft[i][j] = j + 1;
        }
    }
}
void solve()
{
    cnt = new bit_int(h);
    sum_x = new bit_double(h);
    sum_y = new bit_double(h);
    for (int i = 1; i <= h; ++i)
    {
        double x = (n % 2 ? n / 2 + 1 : (double)(n + 1) / 2);
        for (int j = 1; j <= n; ++j)
        {
            if (i & 1)
            {
                cnt->add(i, 1);
                sum_x->add(i, x);
                sum_y->add(i, j);
            }
            else
            {
                cnt->add(i, 1);
                sum_x->add(i, j);
                sum_y->add(i, x);
            }
        }
    }
    for (int tt = 1; tt <= m; ++tt)
    {

        int l, k;
        cin >> l >> k;
        double x = (n % 2 ? n / 2 + 1 : (double)(n + 1) / 2);
        if (l % 2)
        {
            cnt->add(l, -1);
            sum_x->add(l, -x);
            sum_y->add(l, -k);
        }
        else
        {
            cnt->add(l, -1);
            sum_x->add(l, -k);
            sum_y->add(l, -x);
        }
        remove(l, k);
        for (int i = l; i >= 1; --i)
        {
            if (!check(i))
            {
                cout << "yes\n"
                     << tt;
                return;
            }
        }
    }
    cout << "no";
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