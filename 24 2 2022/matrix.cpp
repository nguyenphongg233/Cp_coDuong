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
const long long  MAX = 1005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘
// định lí việt hoàn : Hợp lí != đúng

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
matrix add(matrix a,matrix b,ll n){
    matrix c(n,vi(n,0));
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j< n;j++){
            c[i][j] = (a[i][j] + b[i][j]) % mod;
        }
    }
    return c;
}
matrix pow(matrix a,ll n,ll b){
    if(b == 1)return a;
    else {
        matrix tmp = pow(a,n,b/2);
        if(b & 1)return add(add(tmp,matrix_multiplication(tmp,n,n,power(a,n,b/2),n,n),n),power(a,n,b),n);
        // return tmp + tmp*(a^(n/2)) + a^n
        else return add(tmp,matrix_multiplication(tmp,n,n,power(a,n,b/2),n,n),n);
        // return tmp + tmp*(a^(n/2)) 
    }
}
signed main(){
    faster();
    matrix a = {{1,2,3},{4,5,6},{7,8,9}};
    ll n=  3;
    matrix c = power(a,3,2);
    matrix b = matrix_multiplication(a,n,n,a,n,n);
    for(ll i = 0;i<3;i++){
        for(ll j = 0;j<3;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(ll i = 0;i<3;i++){
        for(ll j = 0;j<3;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}