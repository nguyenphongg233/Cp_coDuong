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
const long long  MAX = 10000005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

ll n,m,k;

ll a[MAX];
ll b[MAX];
ll possible[MAX];



signed main(){
    faster();
    
    cin>>n>>m>>k;

    for(ll i = 1;i<=n;i++)cin>>a[i];

    for(ll j = 1;j<=m;j++)cin>>b[j];
    

    for(ll i = 0;i < MAX ;i++)possible[i] = k;
    sort(a + 1 , a + 1 + n);
    sort(b + 1 , b + 1 + m);

    for(ll i = 1;i<=n;i++){
        possible[a[i]]--;
        if(possible[a[i]] < 0)return cout<<-1,0;
    }

    ll pos = 0;
    ll d = 0;
    for(ll i = 1;i<=m;i++){
        while(possible[pos] == 0)pos++;
        if(pos > b[i])continue;
        else possible[pos]--,d++;
    }

    cout<<d;

    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}