
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
const int MMax = (1 << 15) - 1;
const int MMin = -(1 << 15);
const int temp = 40000;
vector<string> s;
vector<string> split(string s)
{
    vector<string> ret;
    stringstream ss(s);
    string buf;
    while (ss >> buf)
    {
        ret.push_back(buf);
    }
    return ret;
}

void solve()
{
    // for (auto x : s)
    // {
    //     cout << x << ",";
    // }
    // cout << endl;
    if (s.size() == 8 || s.size() == 4)
        s.pop_back();
    if (s.size() == 7)
    {
        int l = atoi(s[2].c_str());
        int r = atoi(s[6].c_str());
        if (l <= r)
        {
            a[l + temp]++;
            a[r + temp + 1]--;
        }
    }
    else
    {
        int x = atoi(s[2].c_str());
        if (s[1] == ">=")
        {
            a[x + temp]++;
            a[MMax + temp + 1]--;
        }
        else
        {
            a[MMin + temp]++;
            a[x + temp + 1]--;
        }
    }
}

void read()
{
    string buff;
    while (getline(cin, buff))
    {
        s = split(buff);
        solve();
    }
    foru(i, 1, maxn - 2)
    {
        a[i] += a[i - 1];
    }
    vector<string> ans;
    foru(l, MMin + temp, MMax + temp)
    {
        if (a[l] == 0)
            continue;
        int r = l;
        while (r + 1 <= MMax + temp && a[r + 1])
            r++;
        if (l == MMin + temp && r == MMax + temp)
        {
            cout << "true";
            return;
        }
        if (l == MMin + temp)
        {
            ans.push_back("x <= " + to_string(r - temp));
        }
        else if (r == MMax + temp)
        {
            ans.push_back("x >= " + to_string(l - temp));
        }
        else
        {
            ans.push_back("x >= " + to_string(l - temp) + " && x <= " + to_string(r - temp));
        }
        l = r;
    }
    if (ans.size() == 0)
    {
        cout << "false";
        return;
    }
    for (auto x : ans)
    {
        cout << x;
        if (x != ans[ans.size() - 1])
            cout << " ||\n";
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
    // int test;
    // cin >> test;
    // while (test--)
    {
        read();
    }
    return 0;
}