#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9+7;
const ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(ll i = a;i < b;i++)
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
ll dp[(60 * 10000) + 5][6];
vll color[6];
vector<vector<int> >adj;
map<ll,int>label;
ll c[(60 * 10000) + 5];
ll solve(int i,int j){
    if(c[i] != -1 && c[i] != j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans = 0;
    ll sum[2] = {0};
    for(auto x:color[j]){
        f(j,0,adj[i].size()){
            sum[j] += solve(adj[i][j],x);
            sum[j] %= INF;
        }
    }
    if(adj[i].empty()){
        sum[0] = sum[1] = 1;
    }
    if((ll)adj[i].size() == 1){
        sum[1] = 1;
    }
    ans = (sum[0] * sum[1]) % INF;
    return dp[i][j] = ans;
}
ll power(ll a,ll b,ll mod){
    if(b == 0){
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2){
        ans *= a;
    }
    return ans % mod;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    color[0] = {1,2,4,5};
    color[1] = {0,2,3,5};
    color[2] = {0,1,3,4};
    color[3] = {1,2,4,5};
    color[4] = {0,2,3,5};
    color[5] = {0,1,3,4};
    map<string,ll>mp;
    mp["white"] = 0;
    mp["blue"] = 1;
    mp["red"] = 2;
    mp["yellow"] = 3;
    mp["green"] = 4;
    mp["orange"] = 5;
    memset(dp,-1,sizeof dp);
    memset(c,-1,sizeof c);
    ll k;
    cin>>k;
    ll n;
    cin>>n;
    ll posoi = (1LL<<k) - 1;
    int lab = 0;
    map<ll,int>ar;
    f(i,0,n){
        ll x;
        cin>>x;
        string s;
        cin>>s;
        ar[x] = mp[s];
        ll cur = x;
        while(cur >= 1 && !label.count(cur)){
            label[cur] = lab;
            lab++;
            posoi--;
            cur /= 2;
        }
    }
    adj.assign(lab + 5,vector<int>());
    for(auto x:label){
        if(ar.count(x.F)){
            c[x.S] = ar[x.F];
        }
        if(label.count(x.F * 2)){
            adj[x.S].pb(label[x.F * 2]);
        }
        if(label.count(x.F * 2 + 1)){
            adj[x.S].pb(label[x.F * 2 + 1]);
        }
    }
    ll ans = power(4,posoi,INF);
    ll sum = 0;
    f(j,0,6){
        sum += solve(label[1],j);
        sum %= INF;
    }
    ans *= sum;
    ans %= INF;
    cout<<ans<<"\n";
}