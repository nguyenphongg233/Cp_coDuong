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
const long long  MAX = 5005;
const long long  INF = 361700864190383365;
const long long mod = 1e9 + 7;

// Nguyễn Phongg :))
using namespace std;

ll n,a[MAX],dp[MAX];

signed main(){
       faster();
       cin>>n;
       FOR(i,1,n)cin>>a[i];
       dp[1] = dp[0] = 0;
       FOR(i,2,n){
           ll d = 1;
           if(a[i]>=a[i-1]){
                  dp[i] = dp[i-1];
                  continue;
           }
           else dp[i] = dp[i-1] + 1,d++;
           FOD(j,i-2,1){
                 if(a[i]<a[j])d++;
                 dp[i] = min(dp[i],dp[j] + d);
           }
       }
       FOR(i,1,n)cout<<dp[i]<<" ";
       cout<<dp[n];
       return 0;
}