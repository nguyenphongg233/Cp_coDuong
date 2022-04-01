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
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

bool cmp(ll a,ll b){
    return a > b;
}


signed main(){
    faster();
    
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        vi a(n);
        for(auto &x : a)cin>>x;

        string s;
        cin>>s;

        vi left,right;

        for(ll i = 0;i<n;i++){
            if(s[i] == 'B')left.push_back(a[i]);
            else right.push_back(a[i]);
        }

        bool check = 1;

        sort(left.begin(),left.end());
        sort(right.begin(),right.end(),cmp);
        for(ll i = 0;i<left.size();i++){
            if(left[i] < i + 1)check = 0;
        }
        for(ll i = 0;i < right.size();i++){
            if(right[i] > n - i)check = 0;
        }

        cout<<(check ? "YES" : "NO")<<"\n";
    }
    
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}