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

ll n,a[MAX],dp[MAX];
unordered_map<ll,ii> mp;

signed main(){
    faster();
    cin>>n;
    dp[0] = 0;
    FOR(i,1,n){
        cin>>a[i];
        if(a[i])dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1] - 1;
        if(mp.count(dp[i]))mp[dp[i]].Y = i;
        else mp[dp[i]].X = i;
    }
    ll maxx = 0;
    for(auto e: mp)maxx = max(maxx,e.Y.Y - e.Y.X);
    cout<<maxx;
    return 0;
}