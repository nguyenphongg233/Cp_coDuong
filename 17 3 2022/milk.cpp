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
const long long  MAX = 1e7 + 5;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,m,k,a[MAX],b[MAX],f[MAX];



signed main(){
    faster();
    
    cin>>n>>m>>k;

    memset(f,k,sizeof k);

    for(ll i = 1;i<=n;i++)cin>>a[i];

    for(ll i = 1;i<=m;i++)cin>>b[i];

    sort(b + 1,b + 1 + m);
    ll full = m + 1;
    for(ll i = m;i >= 1;i--){
        if(f[a[i]] > 0){
            f[a[i]]--;
            if(f[a[i]] == 0)full = a[i];
        }
        else{
            if(f[full - 1] > 0){
               f[full - 1]--;
               if(f[full - 1] == 0)full--;
            }else {
                full--;
                f[full - 1]--;
            }
        }
    }

    
    
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}