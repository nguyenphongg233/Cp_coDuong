#include<bits/stdc++.h>

#define ll long long

const long long MAX = 1e5 + 5;
const long long mod = 1e9;

using namespace std;

ll f[MAX],n,m,a[MAX],pref[MAX],d[MAX];


signed main(){
    
    cin>>n>>m;

    for(ll i = 1;i<=m;i++){
        ll l,r,k;
        cin>>l>>r>>k;
        d[l] = (d[l] + k) % mod;
        d[r + 1] = (d[r + 1] - k) % mod;
        f[r + 1] = (f[r + 1] - (r - l + 1) * k)%mod;
    }

    ll p = 0,sum = 0;

    for(ll i = 1;i<=n;i++){
        p = (p + d[i]) % mod;
        sum = (sum + p + f[i])%mod;
        cout<<(sum + mod ) % mod<<" ";
    }
    
}