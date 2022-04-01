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
const long long  MAX = 1005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

string s;
ll f[MAX][MAX];
bool check(string res){
    for(ll i = 0; i < res.size() / 2; i++) 
        if(res[i] != res[res.size() - i - 1]) return 0;
    return 1;
}
signed main(){
    faster();
    getline(cin, s);
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++){
        string x = "";
        for(ll j = i; j < s.size(); j++){
            x += s[j];
            if(check(x)) ans = max(ans, j - i + 1);
        }
    }
    string t = s;
    reverse(t.begin(), t.end());
    ll n = t.size();
    t = " " + t;s = " " + s;
    f[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i] == t[j]) f[i][j] = max(f[i-1][j-1] + 1, 1ll);
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout << ans << '\n' << f[n][n];
    return 0;
}
