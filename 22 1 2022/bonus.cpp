#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1005;
const long long  INF = 1e18;
const long long mod =  111539768;

// Author : NguyenPhongg
// Date : 21 1 2022
// NT --> NH --> NU 

using namespace std;

ll m,n,k,x,y,u,v;
ll power(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll t = power(a, b / 2, mod);
    t = (t * t) % mod;
    if (b % 2) t = (t * a) % mod;
    return t;
}
signed main(){
    //faster();
    cin>>m>>n>>k>>x>>y>>u>>v;
    // thay vi dung mang cong don nhu sub 1 
    // ap dung cong thuc la ra 
    ll a = ((power(k, v, mod * (k - 1)) - 1) / (k - 1)) % mod;
    ll b = ((power(k, y-1, mod * (k - 1)) - 1) / (k - 1)) % mod;
    cout << a - b;
    return 0;
}