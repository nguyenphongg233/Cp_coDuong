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
const long long  MAX = 200005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 21 1 2022
// NT --> NH --> NU 

using namespace std;

ll n;
bool dp[MAX];
ll pdt1[MAX],pdt2[MAX];
ii a[MAX];

signed main(){
    faster();
    cin>>n;
    FOR(i,1,n)cin>>a[i].X>>a[i].Y;
    sort(a+1,a+1+n);
    pdt1[0] = pdt2[n+1] = -INF;
    memset(dp,1,sizeof dp);
    FOR(i,1,n)pdt1[i] = max(pdt1[i-1],a[i].X + a[i].Y);
    // co the dung duoc = cac cot thu loi trc do 
    FOR(i,1,n)if(a[i].X + a[i].Y <= pdt1[i-1])dp[i] = 0;
    // sau no 
    FOD(i,n,1)pdt2[i] = max(pdt2[i+1],a[i].Y - a[i].X);
    FOR(i,1,n)if(a[i].Y - a[i].X <= pdt2[i+1])dp[i] = 0;
    ll ans = accumulate(dp+1,dp+1+n,0);
    if(!ans)cout<<1;
    else cout<<ans;
    return 0;
}