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

ll n,a[MAX],dp[MAX][MAX];
ll maxx = 0;
signed main(){
    faster();
    cin>>n;
    FOR(i,1,n)cin>>a[i];
    FOR(i,1,n)FOD(j,n,1){
        if(j<=i)break;
        dp[i][j] = max(a[i] * a[j],dp[i-1][j+1] + a[i]*a[j]);
        maxx = max(maxx,dp[i][j]);
    }
    cout<<maxx;
    return 0;
}