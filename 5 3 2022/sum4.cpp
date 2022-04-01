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
const long long  MAX = 100505;
const long long N = 105;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,q,l,r,k,x;
ll a[MAX];
ll dp[MAX][N],pref[MAX][N];



signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    cin>>q;
    while(q--){
        cin>>l>>r>>k>>x;
        if(k <= 100){
            dp[l][k] += x;
            dp[r + k][k] -=x;
        }else{
            for(ll i = l;i<=r;i += k)a[i] += x;
        }
    }
    // chi phi mang = 1e5 * 1e2 = 1e7;
    // chi phi xu li truy van k > 100 = 1e5 * (1e5/1e2) = 1e8 ? |: )  
    for(ll i = 1;i<=n;i++){
        for(ll j = 0;j<=100;j++){
            if(i - j < 0)pref[i][j] = dp[i][j];
            else pref[i][j] = pref[i-j][j] + dp[i][j];
        }
    }
    for(ll i = 1;i<=n;i++){
        ll sum = 0;
        for(ll j = 1;j<=100;j++){
            //cout<<pref[i][j]<<" ";
            sum += pref[i][j];
        }
        //cout<<"\n";
        cout<<sum + a[i]<<" ";
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}