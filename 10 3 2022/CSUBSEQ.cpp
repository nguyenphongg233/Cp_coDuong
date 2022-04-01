#include<bits/stdc++.h>

#define int long long

const long long MAX = 1e6 + 5;
const long long mod = 123456789;

using namespace std;

int n,a[MAX],dp[MAX],cnt[MAX];


signed main(){
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    memset(cnt,0,sizeof cnt);

    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        if(cnt[a[i]] != 0)dp[i] = (dp[i-1] * 2  -  (dp[cnt[a[i]] - 1]) + mod) % mod;
        else dp[i] = (dp[i-1] * 2)%mod;
        cnt[a[i]] = i;
    }
    
    cout<<dp[n] % mod;
    
    
}