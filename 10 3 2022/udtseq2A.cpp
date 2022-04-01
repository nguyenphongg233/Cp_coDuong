#include<bits/stdc++.h>

#define int long long
const long long MAX = 1e5 + 5;
const long long mod = 1e9;
using namespace std;


int t[MAX],f[MAX];


signed main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int l,r,k;
        cin >> l >> r >> k;
        t[l] = ( t[l] + k) %mod;
        t[r+1] = (t[r + 1] - k) % mod;
        f[r+1] = (f[r + 1] - (r-l+1)*k)%mod;
    }
    int sum = 0,p = 0;
    for(int i = 1; i <= n; i++){
        p = (p + t[i])%mod;
        sum = (sum +p+f[i])%mod;
        cout << (sum+mod)%mod << " ";
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}