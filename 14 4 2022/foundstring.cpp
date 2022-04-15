#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1000005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// ?? ??

using namespace std;

ll n,hashS[MAX],poww[MAX],base;



// a = 1 
// abc != bc

ll gethash(ll i,ll j){
    return (hashS[j] - hashS[i-1] * poww[j - i + 1] + mod*mod)%mod;
}

signed main(){
    faster();
    string a,b;
    cin>>b>>a;
    ll n = a.size(),m = b.size();
    a = " " + a;
    b = " " + b;
    base = 26;
    poww[0] = 1;
    for(ll i = 1;i<=n;i++)poww[i] = (poww[i-1] * base)%mod;
    for(ll i = 1;i<=n;i++){
        hashS[i] = (hashS[i-1] * base + a[i] - 'a' + 1)%mod;
    }
    ll hashB = 0;
    for(ll i = 1;i<=m;i++){
        hashB = (hashB * base + b[i] - 'a' + 1)%mod;
    }
    
    vector<ll> step;
    for(ll i = 1;i<=n - m + 1;i++){
        if(gethash(i,i + m - 1) == hashB)step.push_back(i);
    }
    
    cout<<step.size()<<"\n";
    
    for(auto e : step)cout<<e<<" ";


    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}
