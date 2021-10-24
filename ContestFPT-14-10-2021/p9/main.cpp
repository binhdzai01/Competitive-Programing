
// binhdzai

#include <bits/stdc++.h>
#define maxn 5005
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
int n, m, dag[maxn];
vector<int> adj[maxn];
vector<int> ans;
vector<string> input;
vector<string> output;
void read()
{
    ans.clear();
    cin >> n;
    foru(i, 1, n)
    {
        dag[i] = 0;
        adj[i].clear();
    }
}

void solve()
{
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