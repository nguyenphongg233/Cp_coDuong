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
const long long  MAX = 100005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n,q,a[MAX],pref[MAX][10];

signed main(){
    faster();
    cin>>n>>q;
    memset(pref,0,sizeof pref);
    for(ll i = 1;i<=n;i++){
        cin>>a[i];
        for(ll j = 0;j<=9;j++){
            if(a[i] % 10 == j)pref[i][j] = pref[i-1][j] + a[i];
            else pref[i][j] = pref[i-1][j];
        }
    }
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        cout<<pref[r][k] - pref[l-1][k]<<"\n";
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}