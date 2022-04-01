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

ll cs[] = {6,2,5,5,4,5,6,3,7,6};
ll n,m;
ll a[10];
ll dp[MAX];
ll tv[MAX];
signed main(){
    faster();
    cin>>n>>m;
    for(ll i = 1;i<=m;i++){
        ll x;cin>>x;
        a[x] = 1;
    }
    if(a[9])a[6] = 0,a[0] = 0;
    if(a[6])a[0] = 0;
    if(a[5])a[2] = 0,a[3] = 0;
    if(a[3])a[2] = 0;
    dp[0] = 0;
    for(ll i = 1;i<=n;i++){
        dp[i] = 0;
        for(ll j = 0;j<=9;j++){
            if(a[j]){
                if(i < cs[j])tv[i] = -1;
                if(i == cs[j])dp[i] = 1,tv[i] = j;
                if(dp[i] < dp[i-cs[j]] + 1 && ((tv[i-cs[j]] >= 0 ) ^ (i - cs[j] == 0))){
                    dp[i] = dp[i-cs[j]] + 1;
                    tv[i] = j;
                }
            }
        }
    }
    //for(ll i = 1;i<=n;i++)cout<<tv[i]<<' ';
    while(n > 0){
        if(tv[n] == -1)break;
        cout<<n <<","<<tv[n]<<" ";
        n -= cs[tv[n]];
        //cout<<n<<" ";
    }
    return 0;
}