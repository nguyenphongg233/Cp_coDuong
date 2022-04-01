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
const long long  MAX = 100005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;



matrix  matrix_multiplication(matrix a,ll n,ll m,matrix b,ll q,ll p){
    matrix c(n,vi(p,0));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<p;j++){
            c[i][j] = 0;
            for(ll k = 0;k<m;k++){
                c[i][j] += a[i][k]*b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
// phep luy thua thuc hien dc khi n == m;
matrix power(matrix a,ll n,ll b){
    if( b == 1)return a;
    else {
        matrix s = power(a,n,b/2);
        if ( b & 1) return matrix_multiplication(matrix_multiplication(s,n,n,s,n,n),n,n,a,n,n);
        else return matrix_multiplication(s,n,n,s,n,n);
    }
}
signed main(){
    faster();
    matrix c = {{0,1},{2,1}};
    matrix q = {{1},{3}};
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        matrix m = power(c,2,n-1);
        matrix p = matrix_multiplication(m,2,2,q,2,1);
        // p = c^(n-1) * q;
        cout<<p[0][0]<<'\n';
    }
}