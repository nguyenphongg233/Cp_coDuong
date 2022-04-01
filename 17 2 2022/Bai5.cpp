#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,dp[MAX];

signed main(){
    faster();
    cin>>n;
    dp[1] = 3;dp[2] = 8;
    ll res = 2;
    for(ll i = 3;i<=n;i++){
        dp[i] = (dp[i-1]*3 - res + mod)%mod;
        res = (res + mod)%mod;
        res = dp[i-1] - (res%mod);
    }
    cout<<dp[n];
    return 0;
}