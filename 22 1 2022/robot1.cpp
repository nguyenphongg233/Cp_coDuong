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
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 22 1 2022
// NT --> NH --> NU 

using namespace std;

ll n,m;
vector<vi> dp;
vector<vector<ii>> a;
vector<vector<bool>> d;
ll dx[] = {0,0,-1,1};
ll dy[] = {1,-1,0,0};
bool check(ll x,ll y){
    if(x<1||y<1||y>m||x>n)return false;
    else return true;
}
ll cacl(ll i,ll j){
    if(!check(i,j))return 0;
    if(d[i][j])return dp[i][j];
    d[i][j] = 1;
    dp[i][j] = a[i][j].Y;
    FOR(z,0,3){
        ll x = i + dx[z];
        ll y = j + dy[z];
        if(check(x,y) && a[x][y].X < a[i][j].X)dp[i][j] =  max(cacl(x,y) + a[i][j].Y,dp[i][j]);
    }
    return dp[i][j];
}
signed main(){
    faster();
    cin>>n>>m;
    dp.resize(n+5,vi(m+5));
    a.resize(n+5,vii(m+5));
    d.resize(n+5,vector<bool>(m+5,0));
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j].X;
    FOR(i,1,n)FOR(j,1,m)cin>>a[i][j].Y;
    ll maxx = -INF;
    FOR(i,1,n){
        FOR(j,1,m){
            maxx = max(cacl(i,j),maxx);
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<maxx;
    return 0;
}