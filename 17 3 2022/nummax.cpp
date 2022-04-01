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

ll n,a[MAX],b;

// sol two-pointer
// test 7 6 1 7 6 1 2 7 7

/*
   test :7 6 1 2 6 5 6 7 7  
   output : 11

   test :7 6 6 6 6 6 6 6 6 
    output : 28


*/



signed main(){
    faster();
    
    cin>>n>>b;

    for(ll i = 1;i<=n;i++)cin>>a[i];

    ll x = 0,y = 0;
    a[0] = INF;
    bool d = 0;
    ll sum = 0;
    vi whywa;
    ll cnt = 0;
    for(ll i = 1;i<=n;i++){
        if(a[i] > b){
            if(d){
                for(auto e : whywa)
                sum += (e - x + 1) * (y - e + 1);
                sum -= (whywa.size() - 1) * (whywa.size()) ;
            }
            x = y = i;
            d = 0;
        }else if(a[i] == b){
            cnt++;
            whywa.push_back(i);
            d = 1;
            y++;
            if(a[i-1] > b)x = y = i;
        }else if(a[i] < b){
            if(a[i-1] > b)x = y = i;
            else y++;
        }
    }

    //cout<<x<<" "<<y<<" "<<found<<'\n';
    if(d && x != y){
        for(auto e : whywa)
                sum += (e - x + 1) * (y - e + 1) - 1;
        sum -= (whywa.size() - 1) * (whywa.size()) ;
    }
    cout<<sum;
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}