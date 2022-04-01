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

ll n, ans = INF;
ll d, x, y, num;

void cacl(ll a, ll b, ll c){
    x = y = num = -INF;
    d = (b * b) - 4 * a * c;
    if(a != 0){
        if(d > 0){
            num = 2;
            x = (- b - sqrt(d)) / (2 * a);
            y = (- b + sqrt(d)) / (2 * a);
        }
        if(d == 0)num = 1,x = (- b) / (2 * a);
        if(d < 0) num = 0;
    }
    else{
        if(b == 0){
            if(c == 0) num = INF;
            else num = 0;
        }
        else{
            num = 1;
            x = (- c) / b;
        }
    }
}

bool check(ll i, ll x){
    if(x * x + i * x - n == 0) return 1;
    return 0;
}
ll sum(ll x){
    ll res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}
signed main(){
    faster();
    cin >> n;
    for(ll i = 1; i < 162; i++){
        cacl(1, i, -n);
        if(num == 0) continue;
        if(num == 1)if(check(i, x) && sum(x) == i) ans = min(ans, x);
        if(num == 2){
            if(check(i, x) && sum(x) == i) ans = min(ans, x);
            if(check(i, y) && sum(y) == i) ans = min(ans, y);
        }
        if(num == INF){
            ll sum = 0, j = i;
            while(j > 9){
                sum = sum * 10 + 9;
                j -= 9;
            }
            if(j > 0) sum = sum * 10 + j;
            ans = min(ans, sum);
        }
    }
    if(ans == INF) cout << -1;
    else cout << ans;
    return 0;
}