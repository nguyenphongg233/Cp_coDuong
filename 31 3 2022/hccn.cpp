/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_hcn
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


ll n,m,k;
bool d[MAX][MAX];
ll pref[MAX][MAX];


ll get(ll x,ll y,ll u,ll v){
    return pref[u][v] + pref[x-1][y-1] - pref[u][y-1] - pref[x - 1][v];
}
signed main(){
    
    cin>>n>>m>>k;
    memset(d,0,sizeof d);

    memset(d,0,sizeof d);
    for(ll i = 1,u,v;i<=k;i++){
        cin>>u>>v;
        d[u][v] = 1;
    }

    pref[1][1] = d[1][1];

    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            if(i == 1 && j == 1)continue;
            pref[i][j] = -pref[i-1][j-1] + pref[i][j-1] + pref[i - 1][j] + d[i][j];
        }
    }
    ll res = 1;
    for(ll x = 1;x<=n;x++){
        for(ll u = x;u<=n;u++){
            for(ll y = 1,v = 1;y<=v,v <= m;y++){
                while(v <= m && get(x,y,u,v) <= 1)v++;
                if(get(x,y,u,v) > 1)v--;
                if(get(x,y,u,v) == 1)
                res = max((u - x + 1) * (v - y + 1),res);
            }
        }
    }

    cout<<res;
    
}