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
const long long  MAX = 3005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 20 1 2022
// NT --> NH --> NU 

using namespace std;

ll n,t;
ii a[MAX];
ll dp[MAX][MAX];
// dp[i][j] : xet den cuc thu i voi tg la j;

bool cmp(ii a,ii b){
    return a.Y<b.Y;
}
signed main(){
    faster();
    cin>>n>>t;
    ll minxx = 0;
    ll maxx = 0;
    FOR(i,1,n)cin>>a[i].Y>>a[i].X,minxx = max(minxx,a[i].Y);
    memset(dp,0,sizeof dp);
    sort(a+1,a+1+n,cmp);
    FOR(i,1,n)FOR(j,0,t + minxx ){
        dp[i][j] = dp[i-1][j];
        if(j>=a[i].Y && j - a[i].Y < t)dp[i][j] = max(dp[i][j],dp[i-1][j-a[i].Y] + a[i].X);
        maxx = max(maxx,dp[i][j]);
        // a,b la so nguyen nen de dang cm duoc j-a[i].Y < t la thoi diem dao xong cuc vang va chuyen sang cuc vang thu i :)
    }
    cout<<maxx;
    return 0;
}

