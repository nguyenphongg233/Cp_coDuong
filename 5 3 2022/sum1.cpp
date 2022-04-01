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

ll n,a[MAX];
ll bit1[MAX],bit2[MAX];

void up(ll id,ll val,ll bit[]){
    for(;id <= n;id += id&-id)bit[id] += val;
}

void update_range(ll l,ll r,ll val){
    up(l,val,bit1);
    up(r + 1,-val,bit1);
    up(l,(l-1)*val,bit2);
    up(r+1,-r*val,bit2);
}

ll get(ll id,ll bit[]){
    ll sum = 0;
    for(;id > 0;id-=id&-id)sum += bit[id];
    return sum;
}

ll getrange(ll l,ll r){
    return (get(r,bit1)*r - get(r,bit2)) - (get(l-1,bit1) * (l-1) - get(l-1,bit2));
}

signed main(){
    faster();
    
    cin>>n;
    memset(bit1,0,sizeof bit1);
    memset(bit2,0,sizeof bit2);
    for(ll i = 1;i<=n;i++)cin>>a[i],update_range(i,i,a[i]);
    
    ll t;cin>>t;
    while(t--){
        ll e,r,t;
        cin>>e>>r>>t;
        update_range(e,r,t);
    }
    for(ll i = 1;i<=n;i++)cout<<getrange(i,i)<<' ';
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}