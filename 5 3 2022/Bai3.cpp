#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ce(x) cerr << #x << " = " << x << endl
#define len(x) x.size();

#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,a[MAX],q,l,r,k,x;
ll dp[MAX][100],pref[MAX][100];


signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    cin>>q;
    while(q--){
        cin>>l>>r>>k>>x;
        dp[l][l%k] += x;
        dp[r + 1][l%k] -=x;
    }
    for(ll i = 1;i<=n;i++){
        for(ll j = 0;j<100;j++){
            pref[i][j] = pref[i-1][j] + dp[i][j];
        }
    }
    for(ll i = 1;i<=n;i++){
        ll &sum = a[i];
        for(ll j = 0;j<100;j++){
            sum += pref[i][j];
        }
        cout<<sum<<" ";
    }

    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}