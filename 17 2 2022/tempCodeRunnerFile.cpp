#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll cs[] = {6,2,5,5,4,5,6,3,7,6};
ll n,m;
ll a[10];
ll dp[MAX];
ll tv[MAX];
signed main(){
    faster();
    cin>>n>>m;
    for(ll i = 1;i<=m;i++){
        ll x;cin>>x;
        a[x] = 1;
    }
    if(a[9])a[6] = 0,a[0] = 0;
    if(a[6])a[0] = 0;
    if(a[5])a[2] = 0,a[3] = 0;
    if(a[3])a[2] = 0;
    memset(tv,-1,sizeof tv);
    memset(dp,-1,sizeof dp);
    dp[0] = 0;
    for(ll i = 1;i<=n;i++){
        dp[i] = -1;
        for(ll j = 9;j>=0;j--){
            // j la int : so 
            if(a[j] && i >= cs[j] && dp[i-cs[j]] != -1){
                if(dp[i] < dp[i-cs[j]] + 1){
                    dp[i] = dp[i-cs[j]] + 1;
                    tv[i] = j;
                }
            }
        }
    }
    string res = "";
    while(n > 0){
        if(tv[n] == -1)break;
        res += char(tv[n] + '0');
        n -= cs[tv[n]];
    }
    sort(res.rbegin(),res.rend());
    if(res[0] == 0){
        ll y = 0;
        for(ll j = 9;j>=1;j--)if(a[j]){
            y = j;
            break;
        }
        ll p = (cs[y] * cs[0]) / __gcd(cs[y],cs[0]);
        for(ll i = 1;i<=p/cs[y];i++)cout<<y;
        for(ll i = p/cs[0]-1;i<res.size();i++)cout<<res[i];
    }
    cout<<res;
    return 0;
}