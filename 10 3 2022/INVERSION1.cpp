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
const long long N = 505;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

// input : 10 1
// output : 9

ll n,c,f[MAX],g[MAX];

// f : luu dong thu i-1;
// g : dong thu i;

signed main(){
    faster();
    
    cin>> n >> c;

    if(c > (n * (n - 1))/2)return cout<<0,0;

    for(ll j = 0;j<= c;j++){
        if(j == 0)f[j] = 1;
        else f[j] = 0;
    }
    
    for(ll i = 2;i<=n;i++){
        for(ll j = 0;j <= c;j++){
            if(j == 0)g[j] = i;
            else g[j] = g[j-1] + f[j] - f[j-1];
            //cout<<g[j]<<" ";
        }
        //cout<<'\n';
        for(ll j = 0;j <= c;j++){
            f[j] = g[j];
            g[j] = 0;
        }
    }
    
    cout<<f[c];


    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}