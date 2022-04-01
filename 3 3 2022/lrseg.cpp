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
const long long  MAX = 1000005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;


ll n,a[MAX];

signed main(){
    faster();
    cin>>n;
    for(ll i = 1;i<=n;i++)cin>>a[i];
    ll suml = a[1],sumr = a[n],l = 1,r = n;
    ll ans = INF;
    while(l < r){
        ans = min(ans,abs(suml - sumr));
        if(suml < sumr)l++,suml += a[l];
        else r--,sumr += a[r];
    }
    cout<<ans;
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}