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
const long long  MAX = 5005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,a[MAX],b[MAX],dp[MAX][MAX];
// tong lon cua cac so cung do dai khi xet den i,j;

signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    for(ll i = 1;i<=n;i++)cin>>b[i];
    ll res = -INF;
    memset(dp,0,sizeof dp);
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j <= n;j++){
            dp[i][j] = max(a[i] * b[j],dp[i-1][j-1] + a[i] * b[j]);
            res = max(res,dp[i][j]);
        }
    }
    cout<<res;
    return 0;
}