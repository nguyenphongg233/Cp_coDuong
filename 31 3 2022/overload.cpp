/*
  Link Problem : 
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


ll n,m;
ll a[MAX],b[MAX];
ll res[MAX];

signed main(){
    
    cin>>n>>m;

    for(ll i = 1,x;i<=n;i++)cin>>a[i];
    for(ll i = 1,x;i<=m;i++)cin>>b[i];

    ll x = n,y = m;

    while(x >= 1 && y >= 0){
        if(y == 0)while(x >= 1)res[x] = -1,x--;

        while(a[x] > b[y] && x >= 1)res[x] = -1,x--;
        while(b[y - 1] >= a[x] && y >= 1)y--;

        if(a[x] <= b[y])res[x] = y,x--,y--;
    }

    for(ll i = 1;i<=n;i++)cout<<res[i]<<" ";

    
    

}