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


ll n,a[MAX],b;
vi kw,qw;


signed main(){
    faster();
    
    cin>>n>>b;

    for(ll i = 1;i<=n;i++)cin>>a[i];

    qw.push_back(0);
    
    for(ll i = 1;i<=n;i++){
        if(a[i] == b)kw.push_back(i);
        else if(a[i] > b)qw.push_back(i);
    }

    ll sum = 0;
    qw.push_back(n + 1);

    for(ll i = 0,cs1,cs2,cur1,cur2;i<qw.size() - 1;i++){
        cs1 = qw[i];
        cs2 = qw[i + 1];
        cur1 = upper_bound(kw.begin(),kw.end(),cs1) - kw.begin();
        cur2 = upper_bound(kw.begin(),kw.end(),cs2) - kw.begin() - 1;

        if(cur1 > cur2)continue;

        ll t = cs1 + 1;

        for(ll j = cur1,whywa ; j <= cur2 ;j++){
            whywa = kw[j];
            sum += (whywa - t + 1) * (cs2 - whywa);
            t = whywa + 1;
        }
    }

    cout<<sum;
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}