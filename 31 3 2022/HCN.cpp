/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_hcn
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e4 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


ll n,m,k;
vector<vector<bool>> d;
vector<vector<pair<ll,ll>>> dp;

signed main(){
    
    cin>>n>>m>>k;

    d.resize(n + 5,vector<bool>(m + 5,0));
    dp.resize(n + 5,vector<pair<ll,ll>>(m + 5,{0,0}));

    for(ll i = 1,x,y;i<=k;i++){
        cin>>x>>y;
        d[x][y] = 0;
    }

    ll row = 1,col = 1;
    ll res = 0;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            if(d[i][j]){
                dp[i][j].X = i - row + 1;
                dp[i][j].Y = j - col + 1;
                
            }else{
                if(dp[i-1][j].X * dp[i-1][j].Y > dp[i][j-1].X * dp[i][j-1].Y){
                    dp[i][j] = {dp[i-1][j].X + 1,dp[i-1][j].Y};
                }else{
                    dp[i][j] = {dp[i][j-1].X,dp[i][j-1].Y + 1};
                }
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j].X<<" "<<dp[i][j].Y<<"\n";
            res = max(res,dp[i][j].X * dp[i][j].Y);
        }
    }

    cout<<res;
}