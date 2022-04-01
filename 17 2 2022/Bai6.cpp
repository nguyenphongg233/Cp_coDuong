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
const long long  MAX = 305;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,m,a[MAX][MAX],dp[MAX][MAX];
ll cacl(int u, int v, int s, int t) {
	return dp[s][t] - dp[s][v - 1] - dp[u - 1][t] + dp[u - 1][v - 1];
}
signed main(){
    faster();
    cin>>n>>m;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,0,sizeof dp);
    for(ll i = 1;i<=n + 2;i++){
        for(ll j = 1;j<=m + 2;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
        }
    }
    ll res = -INF;
    for(ll u = 1;u < n;u++){
        for(ll v = u+1;v <= n;v++){
           ll sum = cacl(u,m,v,m);

           for(ll j = m - 1;j >= 1; j--){
               ll t = cacl(u,j,v,j);
               res = max(res,t + sum);
               sum = max(sum + a[u][j] + a[v][j],t);
           }
        }
    }

    
    cout<<res;
    return 0;
}