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
const long long  MAX = 500005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;


ll n,a[MAX];

ll solve(ll l,ll r){
    ll cnt[MAX];
    memset(cnt,0,sizeof cnt);
    ll res = 0;
    for(ll i = l;i<=r;i++){
        if(!cnt[a[i]])cnt[a[i]] = 1,res++;
    }
    return res;
}


signed main(){
    faster();
    
    cin>>n;

    for(ll i = 1;i<=n;i++)cin>>a[i];

    // nen so 

    ii val[MAX];

    for(ll i = 1;i<=n;i++)val[i] = {a[i],i};

    sort(val + 1,val + 1 + n);

    ll last = val[1].X;
    a[val[1].Y] = 1;
    ll d = 1;
    for(ll i = 2;i<=n;i++){
        if(val[i].X != last){
            d++;
            last = val[i].X;
            a[val[i].Y] = d;
        }else a[val[i].Y] = d;
    }
    vi no;
    for(ll i = 1;i * i <= n;i++){
        if(n%i == 0){
            no.push_back(i);
            if(n/i != i)no.push_back(n/i);
        }
    }

    sort(no.begin(),no.end());

    cout<<no.size()<<'\n';
    // log (n);
    for(auto x : no){
        cout<<x<<" ";
        //cout<<"#x = "<<x<<" : \n";
        if(x == 1){
            cout<<1<<"\n";
            continue;
        }
        ll ans = INF;
        // dpt = n;
        // start
        for(ll i = 1;i <= n - x + 1;i = i + x){
            //cout<<i<<","<<i + x - 1<<"\n";
            ans = min(ans,solve(i,i + x - 1));
        }
        // end
        cout<<ans<<'\n';
    }
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}