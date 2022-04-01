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
const long long  MAX = 10005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 20 1 2022
// NT --> NH --> NU 

using namespace std;

ll n,m;
struct node{
   ll w,v,a;
}sp[MAX];
ll dp[105][10005];
signed main(){
    faster();
    cin>>n>>m;
    FOR(i,1,n)cin>>sp[i].w>>sp[i].v>>sp[i].a;
    FOR(i,1,m)dp[0][i] = 0;
    FOR(i,1,n){
         FOR(j,1,m){
              dp[i][j] = max(dp[i-1][j],dp[i][j]);
            FOR(z,1,sp[i].a){
                if(z*sp[i].w>j)break;
                if(z * sp[i].w <= j)dp[i][j] = max(dp[i][j],dp[i-1][j-z*sp[i].w] + z*sp[i].v);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}