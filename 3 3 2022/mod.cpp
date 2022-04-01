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

ll m;
ll cacl(ll a, ll b) {
    if(b <= 1) {
        return (!b) ? 0 : a;
    }

    ll s = cacl(a, b / 2);
    return (b % 2) ? (s + s + a) % m : (s + s) % m;
}

struct Matrix{
    ll a[4][4];
    ll row,col;
    Matrix(){
        row = 0,col = 0;
        memset(a,0,sizeof a);
    }
    Matrix(ll n,ll m){
        row = n,col = m;
        memset(a,0,sizeof(a));
    }
    Matrix operator * (const Matrix & x) const{
        Matrix res(row,x.col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < x.col; ++j) {
                res.a[i][j] = 0;
                for (int k = 0; k < col; ++k) {
                    res.a[i][j] = (res.a[i][j] + cacl(a[i][k], x.a[k][j])) % m;
                }
            }
        }
        return res;
    }
};

Matrix power(Matrix a,ll b){
    if(b == 1)return a;
    Matrix s = power(a,b/2);
    return (b & 1 ? s * s * a : s * s);
}

ll p[MAX];
signed main(){
    faster();
    ll t;cin>>t;
    p[0] = 1;
    for(ll i = 1;i<=18;i++)p[i] = p[i-1] * 10;
    while(t--){
        Matrix A(1,2),X(2,2);
        ll x,n;
        cin>>x>>n>>m;
        if(n == 1){
            cout<<x % m<<"\n";
            continue;
        }
        ll sz = to_string(x).size();
        A.a[0][0] = x % m, A.a[0][1] = 1;
        X.a[0][0] = p[sz] % m, X.a[1][0] = x % m, X.a[0][1] = 0, X.a[1][1] = 1;

        X = power(X, n - 1);
        A = A * X;

        cout << A.a[0][0] << '\n';
    }
    
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}