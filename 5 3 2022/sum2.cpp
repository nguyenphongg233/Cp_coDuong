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
const long long  MAX = 505;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,m,a[MAX][MAX],dp[MAX][MAX],q,pref[MAX][MAX];


signed main(){
    faster();
    cin>>n>>m;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    cin>>q;
    memset(dp,0,sizeof dp);
    while(q--){
        ll x,y,u,v,w;
        cin>>x>>y>>u>>v>>w;
        dp[x][y] += w;
        dp[u+1][v+1] += w;
        dp[u + 1][y] -=w;
        dp[x][v + 1] -=w;
    }
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + dp[i][j];
        }
    }
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            cout<<pref[i][j] + a[i][j]<<' ';
        }
        cout<<"\n";
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}