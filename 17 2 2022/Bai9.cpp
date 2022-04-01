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
const long long  MAX = 40005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

signed main(){
    faster();
    ll t;
    cin>>t;
    while(t--){
        ll n,k,a[205];
        cin>>n>>k;
        for(ll i = 1;i<=n;i++)cin>>a[i],a[i]-=k;
        ll dp[205][2*MAX];
        for(ll i = 1;i<=n;i++){
            for(ll j = 0;j<MAX;j++){
                dp[i][j + MAX] = dp[i-1][j+MAX] + dp[i-1][j-a[i] + MAX];
            }
        }
        cout<<dp[n][0]<<"\n";
    }
    return 0;
}