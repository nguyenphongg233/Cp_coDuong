/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_tbg
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;


ll x,y,z,t;

bool check(ll val){
    ll t0 = t - val;
    if(t0 * y + val * y < z * x )t0++;
    if(t0 <= 0)return true;

    // t0 - > thoi gian sau 

    ll sum = val * y;

    //cout<<"\n#val = "<<val<<" , #t = "<<t0<<" :\n";
    //cout<<sum<<" "<<"\n";
    for(ll i = 1;i <= z;i++){
        //cout<<x * i<<" "<<sum<<" ";
        sum += y;
        if(sum < x * i)return True;
        //cout<<sum<<"\n";
    }
    return true;
}

signed main(){
    
    cin>>x>>y>>z;

    t = (x * z / y);
    while(t * y < x * z)t++;

    //cout<<t<<"\n";

    ll l = 0,r = 1e9;
    ll res = 0;
    while(l <= r){
        ll m = l + r >> 1;
        //cout<<l <<" "<<r<<" "<<m <<" "<<check(m)<<"\n";
        if(check(m))res = m,r = m - 1;
        else l = m + 1;

    }

    cout<<res;


    
    
}