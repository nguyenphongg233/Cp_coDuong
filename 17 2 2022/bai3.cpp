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
const long long  MAX = 1005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,m,a[MAX][MAX],res[MAX],dp[MAX][MAX];
// dp[i][j] : loi nhuan toi da khi dau tu i ty dong vao j mon do dau tien 
signed main(){
    faster();
    cin>>n>>m;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ll ans = 0;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            if(i == 1)dp[i][j] = max(a[i][j],dp[i][j-1]);
            else{
                dp[i][j] = max(dp[i][j-1],a[i][j]);
                for(ll z = 1;z < i;z++){
                    dp[i][j] = max(dp[i][j],dp[z][j-1] + a[i-z][j]);
                }
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}