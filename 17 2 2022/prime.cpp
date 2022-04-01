#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll n, t, nt[14000005];
vi p;

signed main(){
    faster();
    memset(nt, 0, sizeof(nt));
    for(ll i = 2; i <= sqrt(14e6); i++){
        if(!nt[i]){
            for(ll j = i * i; j <= 14e6; j += i) nt[j] = 1;
        }
    }
    for(ll i = 2; i <= 14e6; i++) 
        if(!nt[i]) p.push_back(i);
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = 0;
        for(ll i = 0; p[i] * p[i] * p[i] < n; i++){
            ll t = p[i] * p[i] * p[i];
            for(ll j = 0; p[j] * p[j] * t < n; j++){
                if(i == j) continue;
                ll res = p[j] * p[j] * t;
                ll k = upper_bound(p.begin(), p.end(), n / res) - p.begin();
                ans += k;
                if(p[k] > p[i]) ans--;
                if(p[k] > p[j]) ans--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}