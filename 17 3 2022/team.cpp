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
const long long  MAX = 200005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n;
ii a[MAX];
ll pref[MAX];
ll d[MAX];
bool cmp(ii a,ii b){
    return a.Y < b.Y;
}

signed main(){
    faster();
    
    cin>>n;
    
    for(ll i = 1;i<=n;i++)cin>>a[i].X>>a[i].Y;

    sort(a + 1,a + 1 + n,cmp);
    ll minx[MAX];

    minx[n] = a[n].X;

    for(ll i = n-1;i>=1;i--){
        minx[i] = min(minx[i + 1],a[i].X);
    }
    d[1] = a[1].X - a[1].Y;
    for(ll i = 2;i<=n;i++)d[i] = min(d[i-1],a[i].X - a[i].Y);
    pref[0] = 0;
    for(ll i = 1;i<=n;i++){
        pref[i] = (pref[i-1] + a[i].Y);
    }
    for(ll i = 1;i<=n;i++){
        cout<<min(pref[i-1] + minx[i],pref[i] + d[i])<<"\n";
    }
    
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}