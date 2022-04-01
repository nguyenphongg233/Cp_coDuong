#include<bits/stdc++.h>

#define ll int

const long long MAX = 1e5 + 5;
const long long mod = 123456789;

using namespace std;


// input : 10 1
// output : 9

ll n,c,f[MAX],g[MAX];
ll dp[505][MAX];
// f : luu dong thu i-1;
// g : dong thu i;

signed main(){
    
    cin>> n >> c;

    if(c > (n * (n - 1))/2)return cout<<0,0;

   // f[0] = 1;
    dp[1][0] = 1;
    memset(g,0,sizeof g);
    for(ll j = 1;j<=c;j++)f[j] = 0,dp[1][j] = 0;
    for(ll i = 2;i<=n;i++){
        for(ll j = 0;j <= c;j++){
            dp[i][j] = (dp[i][j - 1] + dp[i-1][j] - dp[i-1][j-i]) % mod;
            if(j == 0)g[j] = 1;
            //cout<<j-1;
            else g[j] = (g[j-1] + f[j] - f[j - i]);
        }
        //cout<<dp[i][0]<<" "<<g[0]<<"\n";
        for(ll j = 0;j <= c;j++){
            //cout<<"#j = "<<j<<"\n";
            //cout<<dp[i - 1][j]<<","<<f[j]<<"#";
            f[j] = g[j];
            //cout<<dp[i][j]<<","<<f[j]<<" ";
            //cout<<"\n";
        }
        memset(g,0,sizeof g);
        //cout<<'\n';
    }
    cout<<dp[n][c];
    //cout<<f[c] << " "<<dp[n][c];
    
    
}