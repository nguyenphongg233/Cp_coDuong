#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 505;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,m;
vi a[MAX];

signed main(){
    faster();
    cin>>n>>m;
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            ll x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    ll ans = -INF,res = -1;
    for(ll i = 1;i<=n;i++){
        sort(a[i].rbegin(),a[i].rend());
        if(a[i][0] * a[i][1] > ans){
            ans = a[i][0] * a[i][1];
            res = i;
        }
        ll n = a[i].size() - 1 ;
        if(a[i][n] * a[i][n-1] > ans){
            ans = a[i][n] * a[i][n-1];
            res = i;
        }
    }
    cout<<ans<<' '<<res;
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}