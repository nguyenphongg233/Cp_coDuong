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

ll n,m,k,a[MAX][MAX],minx[MAX],maxx[MAX],dp[MAX][MAX];
bool c1[MAX],c2[MAX];

signed main(){
       faster();
       cin>>n>>m>>k;
       memset(c1,0,sizeof(c1));
       memset(a,0,sizeof(a));
       memset(c2,0,sizeof(c2));
       memset(maxx,0,sizeof(maxx));
       FOR(i,1,n+1)minx[i] = m+1;
       FOR(i,1,k){
           ll u,v;
           cin>>u>>v;
           maxx[u] = max(maxx[u],v);
           minx[u] = min(minx[u],v);
           c1[u] = 1;
           c2[v] = 1;
       }
       while(1){
           ll u,v;
           cin>>u>>v;
           if(u==0 and v==0)break;
           a[u][v] = 1;
       }
       dp[1][1] = 0;
       FOR(i,1,n)maxx[i] = max(maxx[i-1],maxx[i]);
       FOD(i,n,1)minx[i] = min(minx[i+1],minx[i]);
       FOR(i,1,n)FOR(j,1,m){
           dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
           if(a[i][j] == 1 and c1[i]==0 and c2[j]==0){
               if(maxx[i] < j and minx[i] > j)dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
           }
       }
       cout<<dp[n][m];
       return 0;
}