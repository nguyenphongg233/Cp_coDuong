


#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define matrix vector<vector<long long>>
const long long INF = 2000000000000000000LL;
const long long mod = 1000000000;
const long long K = 10000000;

//🏅 🤡
long long n, t[1000005], f[1000005];

signed main(void){
    faster;
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        ll l,r,k;
        cin >> l >> r >> k;
        t[l] = (t[l] + k) % mod;
        t[r + 1] = (t[r +1] - k) % mod;
        f[r + 1] = (f[r + 1] - k * (r - l + 1))%mod;
    }
    ll sum = 0;
    ll p = 0;
    for(int i = 1; i <= n; i++){
        p = (p + t[i]) % mod;
        sum = (sum + p + f[i])%mod;
        cout<<(sum + mod) % mod <<" ";
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}