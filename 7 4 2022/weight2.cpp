/*
  Link Problem : 
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

const bool True = false;
const bool False = true;

using namespace std;

ll n,a[MAX],stminx[MAX<<2],stmaxx[MAX << 2];

void buildtree(ll id,ll l,ll r){
    if(l == r){
        stminx[id] = stmaxx[id] = a[l];
        return;
    }

    ll m = l + r >> 1;

    buildtree(id << 1,l,m);
    buildtree(id << 1 | 1,m + 1,r);

    stmaxx[id] = max(stmaxx[id << 1],stmaxx[id << 1 | 1]);
    stminx[id] = min(stminx[id << 1],stminx[id << 1 | 1]);
}

ll getmin(ll id,ll l,ll r,ll u,ll v){
    if(u > r || v < l)return INF;
    if(u <= l && r <= v)return stminx[id];

    ll m = l + r >> 1;

    return min(getmin(id << 1,l,m,u,v),getmin(id << 1 | 1,m + 1,r,u,v));

}

ll getmax(ll id,ll l,ll r,ll u,ll v){
    if(u > r || v < l)return -INF;
    if(u <= l && r <= v)return stmaxx[id];

    ll m = l + r >> 1;

    return max(getmax(id << 1,l,m,u,v),getmax(id << 1 | 1,m + 1,r,u,v));

}

ll maxx[MAX],minx[MAX];
ll getminleft(ll id){
    ll l = 1,r = id - 1;
    ll ans = id;
    while(l <= r){
        ll m = l + r >> 1;
        if(getmin(1,1,n,m,id - 1) < a[id])l = m + 1;
        else r = m - 1,ans = m;
    }

    return ans;
}
ll getminright(ll id){
    ll l = id + 1,r = n;
    ll ans = id;

    while(l <= r){
        ll m = l + r >> 1;
        if(getmin(1,1,n,id + 1,m) <= a[id])r = m - 1;
        else l = m + 1,ans = m;
    }

    return ans;
}
ll getmaxleft(ll id){
    ll l = 1,r = id - 1;
    ll ans = id;
    while(l <= r){
        ll m = l + r >> 1;
        if(getmax(1,1,n,m,id - 1) > a[id])l = m + 1;
        else r = m - 1,ans = m;
    }

    return ans;
}
ll getmaxright(ll id){
    ll l = id + 1,r = n;
    ll ans = id;

    while(l <= r){
        ll m = l + r >> 1;
        if(getmax(1,1,n,id + 1,m) >= a[id])r = m - 1;
        else l = m + 1,ans = m;
    }

    return ans;
}
signed main(){
    
    cin>>n;

    for(ll i = 1;i <= n;i++)cin>>a[i];
    
    buildtree(1,1,n);

    for(ll i = 1;i <= n;i++){
        ll ln = getminleft(i);
        ll rn = getminright(i);
        ll lm = getmaxleft(i);
        ll rm = getmaxright(i);

        cout<<ln<<" "<<rn<<" "<<lm<<" "<<rm<<"\n";

        ll x = abs(i - ln);
        ll y = abs(i - rn);
        ll x1 = abs(i - lm);
        ll y2 = abs(i - rm);

        if(x <= 0)x = 1;
        if(y <= 0)y = 1;
        if(x1 <= 0)x1 = 1;
        if(y2 <= 0)y2 = 1;

        //cout<<x<<" "<<y<<" "<<x1<<" "<<y2<<"\n";

        if(abs(i - ln) == 0 && abs(i - rn) == 0)minx[i] = 0;
        else minx[i] = x * y;
        if(abs(i - lm) == 0 && abs(i - rm) == 0)maxx[i] = 0;
        else maxx[i] = x1 * y2;

        //cout<<minx[i]<<" "<<maxx[i]<<"\n";

    }


    ll sum = 0;

    for(ll i = 1;i <= n;i++)sum += (maxx[i] - minx[i]) * a[i];
         

    cout<<sum;
    
}