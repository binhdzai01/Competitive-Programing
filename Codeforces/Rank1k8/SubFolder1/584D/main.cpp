
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
bool checkPrime(int x)
{
    foru(i, 2, sqrt(x))
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void read()
{
    cin >> n;
}

void solve()
{
    if (n <= 7)
    {
        cout << 1 << endl;
        cout << n;
        return;
    }
    cout << 3 << endl;
    cout << 3 << " ";
    n -= 3;
    for (int i = 3; i <= n - 3; i += 2)
    {
        if (checkPrime(i) && checkPrime(n - i))
        {
            cout << i << " " << n - i;
            return;
        }
    }
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