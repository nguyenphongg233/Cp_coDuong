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
const long long  MAX = 5005;
const long long  INF = 1e18;
//const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll mod=10000000007;
ll n,k,m,f[5005][5005];

signed main(){
    faster();
    cin>>k>>m>>n;
    ll dem=0;

    for(int i=1;i<m;i++){
        f[1][i]=1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<m;j++){
            if(j+k<m) f[i][j]=(f[i][j]+f[i-1][j+k])%mod;
            if(j-k>0) f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
            f[i][j]%=mod;
        }
    }
    for(int i=1;i<m;i++){
        dem+=f[n][i];
        dem%=mod;
    }
    cout<<dem;
}