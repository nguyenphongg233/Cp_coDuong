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


ll minx[MAX],maxx[MAX];
ll n,a[MAX];
pair<ll,ll> stmin[MAX << 2],stmax[MAX << 2];

void buildtree(ll id,ll l,ll r){
    if(l == r){
        stmin[id].X = a[l];
        stmax[id].X = a[l];
        stmax[id].Y = stmin[id].Y = l;
        return;
    }

    ll m = l + r >> 1;

    buildtree(id << 1,l,m);
    buildtree(id << 1 | 1,m + 1,r);

    stmin[id] = min(stmin[id << 1],stmin[id << 1 | 1]);
    stmax[id] = max(stmax[id << 1],stmax[id << 1 | 1]);

}

pair<ll,ll> getmax(ll id,ll l,ll r,ll u,ll v){
    if(u > r || v < l)return {-INF,-INF};
    if(u <= l && r <= v)return stmax[id];

    ll m = l + r >> 1;
    return max(getmax(id << 1,l,m,u,v),getmax(id << 1 | 1,m + 1,r,u,v));
}

pair<ll,ll> getmin(ll id,ll l,ll r,ll u,ll v){
    if(u > r || v < l)return {INF,INF};
    if(u <= l && r <= v)return stmin[id];

    ll m = l + r >> 1;
    return min(getmin(id << 1,l,m,u,v),getmin(id << 1 | 1,m + 1,r,u,v));
}

signed main(){
    
    cin>>n;

    for(ll i = 1;i <= n;i++)cin>>a[i];

    buildtree(1,1,n);

    for(ll i = 1;i <= n;i++){
        ll l = 1,r = i - 1;
        pair<ll,ll> ans = {a[i],i};
        while(l <= r){
            ll m = l + r >> 1;

            pair<ll,ll> pdt = getmin(1,1,n,m,i - 1);

            if(pdt.X > a[i])r = m - 1,ans = {a[i],m};
            else l = m + 1;
        }

        ll lengthl = i - ans.Y + 1;

        l = i + 1,r = n;
        ans = {a[i],i};


        while(l <= r){
            ll m = l + r >> 1;

            pair<ll,ll> pdt = getmin(1,1,n,i + 1,m);

            if(pdt.X > a[i])l = m + 1,ans = {a[i],m};
            else r = m - 1;
        }

        ll lengthr = ans.Y - i + 1;

        minx[i] = lengthl * lengthr;
        //cout<<i<<" "<<lengthl<<" "<<lengthr<<"\n";
    }

    for(ll i = 1;i <= n;i++){
        ll l = 1,r = i - 1;
        pair<ll,ll> ans = {a[i],i};
        while(l <= r){
            ll m = l + r >> 1;

            pair<ll,ll> pdt = getmax(1,1,n,m,i - 1);

            if(pdt.X < a[i])r = m - 1,ans = {a[i],m};
            else l = m + 1;
        }

        ll lengthl = i - ans.Y + 1;

        l = i + 1,r = n;
        ans = {a[i],i};

        while(l <= r){
            ll m = l + r >> 1;

            pair<ll,ll> pdt = getmax(1,1,n,i + 1,m);

            if(pdt.X < a[i])l = m + 1,ans = {a[i],m};
            else r = m - 1;
        }

        ll lengthr = ans.Y - i + 1;

        maxx[i] = lengthl * lengthr;

    }


    //for(ll i = 1;i <= n;i++)cout<<minx[i]<<" "<<maxx[i]<<"\n";








    ll sum = 0;

    for(ll i = 1;i <= n;i++)sum += (maxx[i] - minx[i]) * a[i];
         

    cout<<sum;
    
}