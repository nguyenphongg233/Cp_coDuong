#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ce(x) cerr << #x << " = " << x << endl
#define len(x) x.size();

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


ll n, m, a[5005], c[MAX];
ll x[MAX], f[MAX];
ll cp[MAX];

signed main(){
    faster();
    
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)cin >> a[i]; 
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= m; i++) cin >> c[i];
    f[0] = 0, c[0] = 0,cp[m+1] = INF;
    for(ll i = m;i>=1;i--)cp[i] = min(cp[i+1],c[i]);
    for(ll i = 1; i <= n; i++){
        f[i] = f[i - 1] + cp[1];
        for(ll j = i; j >= 1; j--){
            if(a[i] - a[j] + 1 <= m) f[i] = min(f[i] , f[j - 1] + cp[a[i] - a[j] + 1]);
        }
    }
    cout << f[n];
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}