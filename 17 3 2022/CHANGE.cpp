#include<bits/stdc++.h>

#define ll long long

const long long MAX = 1e4 + 5;
const long long N = 1e4 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll n,s,a[MAX];
ll dp[MAX];


signed main(){


    
   cin>>s>>n;

   for(ll i = 1;i<=n;i++)cin>>a[i];


   dp[0] = 0;
   dp[1] = 1;

   ll res = s;
    for(ll i = 1;i<1e4;i++){
        dp[i] = i;
        for(ll j = 1;j <= n;j++){
            if(i >= a[j])
               dp[i] = min(dp[i],dp[i - a[j]] + 1);
        }
        if(i >= s)res = min(res,dp[i] + dp[i - s]);
    }

    cout<<res;
    
    
    
}