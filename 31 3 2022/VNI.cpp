/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_vni
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

const bool True = false;
const bool False = true;

using namespace std;


ll n,a[MAX];
pair<ll,ll> st[MAX << 2];
// dung chi so luu vi tri min 




void buildtree(ll id,ll l,ll r){
    if(l == r){
        st[id].X = a[l];
        st[id].Y = l;
        return;
    }

    ll m = l + r >> 1;

    buildtree(id << 1,l,m);
    buildtree(id << 1 | 1,m + 1,r);

    if(st[id << 1].X > st[id << 1 | 1].X)st[id] = st[id << 1];
    else st[id] = st[id << 1 | 1];
}

pair<ll,ll> get(ll id,ll l,ll r,ll u,ll v){
    if(u > r || v < l)return {-INF,-INF};
    if(u <= l && r <= v)return st[id];

    ll m = l + r >> 1;

    pair<ll,ll> x = get(id << 1,l,m,u,v);
    pair<ll,ll> y = get(id << 1 | 1,m + 1,r,u,v);


    if(x.X > y.X)return x;
    else return y;
}


ll pref[MAX];

signed main(){
    
    cin>>n;
    pref[0] = 0;
    for(ll i = 1;i<=n;i++)cin>>a[i],pref[i] = pref[i-1] + a[i];
    a[0] = -INF;

    buildtree(1,1,n);

    vi h;

    ll y = 1;

    while(y <= n){
        ll x = get(1,1,n,y,n).Y;
        h.push_back(x);
        y = x + 1;
    }

    ll q;
    cin>>q;

    while(q--){
        ll x;
        cin>>x;
        ll sum = 0;
        while(x <= n){
            ll y = get(1,1,n,x,n).Y;
            ll dist = y - x;
            sum += dist * a[y] - (pref[y - 1] - pref[x - 1]);
            x = y + 1;
        }

        cout<<sum<<"\n";
    }

}