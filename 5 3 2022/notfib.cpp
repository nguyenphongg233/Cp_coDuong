#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ce(x) cerr << #x << " = " << x << endl
#define len(x) x.size();

#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,q,dp[MAX],a,b,c[MAX],l,r;
ll up[MAX],down[MAX];



signed main(){
    faster();
    
    cin>>n>>q>>dp[1]>>dp[2]>>a>>b;
    for(ll i = 3;i<MAX - 4;i++)dp[i] = (dp[i-1] * b%mod + dp[i-2]* a%mod)%mod;
    for(ll i = 1;i<=n;i++)cin>>c[i];

    while(q--){
        cin>>l>>r;
        up[l] = (up[l] + dp[1]) % mod;
        up[l + 1] = (up[l + 1] + dp[2] - b * (dp[1])%mod + mod) % mod;
        down[r + 1] = (down[r + 1] + dp[r - l + 2]) % mod;
        down[r + 2] = (down[r + 2] + dp[r-l + 3] - b*dp[r-l + 2]%mod + mod) % mod;
    }
    
    for(ll i = 1;i<=n;i++){
        if(i > 1){
            up[i] = (up[i] + up[i-1] * b % mod + up[i-2] * a % mod) % mod;
            down[i] = (down[i] + down[i-1] * b%mod + down[i-2] * a%mod) % mod;
        }
        cout<<(c[i] + up[i] - down[i] + mod)%mod<<" ";
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}