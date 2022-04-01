#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 300005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;


ll n,a[MAX];
vi b,c;


signed main(){
    faster();
    
    cin>>n;

    for(ll i = 1;i<=n;i++)cin>>a[i];

    for(ll i = 1;i<n;i+=2){
        b.push_back(a[i] + a[i + 1]);
    }
    for(ll i = 2;i<n;i+=2){
        c.push_back(a[i] + a[i + 1]);
    }

    ll best = -INF;
    ll sum = b[0] + b[1];
    best = max(best,sum);

    for(ll i = 2;i<b.size();i++){
        sum = max(sum + b[i],b[i] + b[i-1]);
        best = max(best ,sum);
    }

    best = max(best,c[0] + c[1]);
    sum = c[0] + c[1];
    for(ll i = 2;i<c.size();i++){
        sum = max(sum + c[i],c[i] + c[i-1]);
        best = max(best ,sum);
    }
    cout<<best;
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}