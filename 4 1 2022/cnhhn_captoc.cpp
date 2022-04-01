#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1005;
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

/*ll n,m,a[MAX][MAX],dp[MAX];
ii b[MAX];


signed main(){
       faster();
       cin>>n>>m;
       memset(b,0,sizeof(b));
       FOR(i,1,n)FOR(j,1,n){
           cin>>a[i][j];
           b[j].X = max(b[j].X,a[i][j]);
           if(a[i][j]!=b[j].X)b[j].Y = max(b[j].Y,a[i][j]);
       }
       ll res = 0;
       dp[1] = b[1].X;
       dp[2] = b[2].X;
       FOR(i,1,n)FOR(j,3,m){
           if(b[j].X==a[i][1]){
               dp[i] = max(a[i][j],dp[j-1]+b[1].Y);
               cout<<"hihi"<<' ';
            }
           else dp[i] = max(a[i][j],dp[i-1]+b[1].X);
           res = max(res,dp[i]);
       }
       cout<<res;
       return 0;
}*/
ll n, m, a[1001][1001], f[1001][1001];

signed main(){
    faster();
    cin >> n >> m;
    FOR(i,1,n)FOR(j,1,m) cin >> a[i][j];
    FOR(i,1,n){
        FOR(j,0,m){
            f[i+1][j] = max(f[i][j], f[i+1][j]);
            FOR(k,1,m-j){
                f[i+1][j+k] = max(f[i+1][j+k], f[i][j] + a[i][k]);
            }
        }
    }
    cout << f[n+1][m];
    return 0;
}