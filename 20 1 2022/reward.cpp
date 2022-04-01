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
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 20 1 2022
// NT --> NH --> NU 

using namespace std;

ll n,a[MAX],dp[MAX],b[MAX];

signed main(){
    faster();
    cin>>n;
    FOR(i,1,n)cin>>a[i],b[a[i]]++;
    // a[i] <= 10000
    dp[0] = 0;
    dp[1] = b[1];
    ll maxx = 0;
    FOR(i,2,MAX){
        dp[i] = max(dp[i-1],dp[i-2] + b[i] * i);
        maxx = max(maxx,dp[i]);
    }
    cout<<maxx;
    return 0;
}