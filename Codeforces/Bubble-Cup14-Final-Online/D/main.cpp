#include <bits/stdc++.h>
using namespace std;

// //#define DB
// #ifdef DB
// #define el cerr << "\n";
// #define db(...) cerr << " [" << #__VA_ARGS__ << " : " << __VA_ARGS__ << "] ";
// #else
// #define el
// #define db(...)
// #endif // DB

// DEBUG
#define format(x) << #x << ": " << (x)
#define com << ", "
#define ndl << "\n"
#define debug1(x) cerr format(x) ndl;
#define debug2(x, y) cerr format(x) com format(y) ndl;
#define debug3(x, y, z) cerr format(x) com format(y) com format(z) ndl;
#define debug4(x, y, z, w) cerr format(x) com format(y) com format(z) com format(w) ndl;
void debug_out()
{
    cerr << "\n";
}
template <typename H, typename... T>
void debug_out(H h, T... t)
{
    cerr << " " << (h);
    debug_out(t...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define el cerr << "\n";
//

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
// define double long double will mess up the debug code
// #define double long double
template <typename T, typename U>
pair<T, U> operator+(const pair<T, U> &L, const pair<T, U> &R)
{
    return {L.first + R.first, L.second + R.second};
}
template <typename T, typename U>
pair<T, U> operator-(const pair<T, U> &L, const pair<T, U> &R)
{
    return {L.first - R.first, L.second - R.second};
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
    int,       // key // if multiset, use pair<T, int> as the key where the int is time when added
    null_type, // value
    less<int>, // comparator (less --> normal set)
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
/*
  How to use ordered_set:
ordered_set os;
os.insert(x);
os.erase(x);
os.find_by_order(k)  returns iterator to kth element starting from 0;
os.order_of_key(x) returns count of elements strictly smaller than x; (Lower bound, 0 based position)
  
  erase, insert same as normal set
*/

//const int MOD = 998244353;
const int MOD = 1e9 + 7; // NEVER use MOD > 2^30 cause multiplication will OVERFLOW long long!!!

// Assume: MOD is coprime with a
ll invMod(ll a)
{
    ll b = MOD, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    return (MOD + u) % MOD;
}

ll mul(ll a, ll b)
{
    // return ((a % MOD) * (b % MOD)) % MOD;  // Safer but slower
    return (a * b) % MOD;
}

ll add(ll a, ll b)
{
    // return ((a % MOD) + (b % MOD)) % MOD;  // Safer but slower
    return (a + b) % MOD;
}

ll sub(ll a, ll b)
{
    // return ((a - b) % MOD + MOD) % MOD;  // Safer but slower
    return (a - b + MOD) % MOD;
}

ll divMod(ll a, ll b)
{
    return mul(a, invMod(b));
}

ll powMod(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

const int N = 1e6 + 5;

ll fact[N];
ll invf[N];
void init_binom()
{
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fact[i] = mul(fact[i - 1], i);
        invf[i] = mul(invf[i - 1], invMod(i));
    }
}
ll C(int k, int n)
{
    return mul(fact[n], mul(invf[k], invf[n - k]));
}
ll catalan(int n)
{
    return sub(C(n, n * 2), C(n + 1, n * 2));
}
#define int long long
#define double long double
void solve()
{
}

/**
 * Frequent bugs:
 *   - Overflows: Are limits on static arrays enough?? Double-check!!
 *      Input is N but we need N * 2? N * 4 (segment tree)?
 *      Is N upto 10^7?
 *      Is int32 enough? Use #define int long long
 *      MOD cannot be greater than 2^30 because multiplication will overflow long long!!!
 *   - 1-off errors:
 *      Is indexing 0-based or 1-based?
 *   - Corner cases:
 *      N == 0?
 *      N == 1?
 *      Impossible?
 *   - Output format:
 *      Special characters? Long 'minus' signs? Copy-and-paste from statement to be sure
 *      New-lines?
 *   - Casting problems:
 *      Function calculates long long but return int --> WA?
 *      Provide long long as argument but the parameter is int --> WA?
 *      Use #define int long long if memory limit is high
 *   - Problem definition: read the statement correctly:
 *      'y' is vowel?
 **/
const int INF = 1e9; // TODO: CHANGE BACK TO 1e9
int query(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}
// int ter(int x, int y, bool swapping) {
//     int L = 2, R = INF - 1, M1, M2, d;
//     while (L + 2 < R) {
//       d = (R - L) / 3;
//       M1 = L + d;
//       M2 = R - d;

//     }
// }
signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int d11 = query(1, 1);   // 3
    int d91 = query(INF, 1); // 7
    int d19 = query(1, INF); // 5
    // db(d11, d91, d19);

    // int dx = d11 - d91; // -4
    // int Lx = (dx > 0 ? dx + 1 : 2); // 2
    // int Rx = (dx < 0 ? INF + dx - 1 : INF - 1); // 5
    // int Mx = (Lx + Rx) / 2; // (2 + 5) / 2 = 3
    int dx = INF + 1 - d91;
    int Mx = (d11 + dx) / 2;

    // db(dx);

    // int dy = d11 - d19; // -2
    // int Ly = (dy > 0 ? dy + 1 : 2); // 2
    // int Ry = (dy < 0 ? INF + dy - 1 : INF - 1); // 7
    // int My = (Ly + Ry) / 2; // (2 + 7) / 2 = 4
    int dy = INF + 1 - d19;
    int My = (d11 + dy) / 2;

    // db(dy);

    // db(Mx, My); // 3 4

    int left = query(1, My);
    int right = query(INF, My);
    int down = query(Mx, 1);
    int up = query(Mx, INF);

    int sideX = INF - left - right;
    int sideY = INF - down - up;
    // db(sideX, sideY); // 4 4

    int halfX = sideX / 2;
    int halfY = sideY / 2;

    int x1 = Mx - halfX + (sideX % 2 == 0);
    int y1 = My - halfY + (sideY % 2 == 0);

    int x2 = Mx + halfX;
    int y2 = My + halfY;

    // // TODO: CHANGE BACK TO 1e9
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
