#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 21 1 2022
// NT --> NH --> NU 

using namespace std;

ll n,q,a[MAX],pref[MAX],minx[MAX];

signed main(){
    faster();
    cin>>n>>q;
    pref[0] = 0;
    FOR(i,1,n)cin>>a[i],pref[i] = pref[i-1] + a[i];
    minx[n] = a[n];
    FOD(i,n-1,1)minx[i] = min(minx[i+1],a[i]);
    //cout<<"\n";
    //FOR(i,1,n)cout<<pref[i]<<' ';
    //cout<<"\nHello chao mung cac streammer : \n";
    while(q--){
        ll x,y;
        cin>>y>>x;
        ll qwe = y + pref[x-1];
        //cout<<qwe<<" ";
        ll k = upper_bound(pref+x+1,pref+1+n,qwe) - pref - 1;
        //cout<<k<<" "<<minx[x]<<" ";
        if(k==x && minx[x] > y){
            cout<<0<<"\n";
            continue;
        }
        if(qwe - pref[k] == 0)cout<<(k - x + 1)<<"\n";
        else if(qwe<pref[k]){
            ll res = k - x ;
            ll minx = qwe - pref[k-1];
            //cout<<minx<<"     ";
            //cout<<"\n";
            FOR(j, k + 1,n){
                 if(minx >= a[j])minx -= a[j],res++;
                 if(minx <= 0)break;
                 //cout<<minx<<" ";
            }
            cout<<res<<"\n";
        }
        else {
            ll res = k - x + 1;
            ll minx = qwe - pref[k];
            //cout<<minx<<"     ";
            //cout<<"\n";
            FOR(j, k + 1,n){
                 if(minx >= a[j])minx -= a[j],res++;
                 if(minx <= 0)break;
                 //cout<<minx<<" ";
            }
            cout<<res<<"\n";
        }
    }
    return 0;
}