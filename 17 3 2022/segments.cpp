#include<bits/stdc++.h>

#define ll long long
#define ii pair<ll,ll>
#define X first
#define Y second

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;

using namespace std;


ll n,a[MAX];
ll pref[MAX];


signed main(){
    
    cin>>n;

    pref[0] = 0;
    vector<ll> no;
    for(ll i = 1;i<=n;i++)cin>>a[i],pref[i] = pref[i-1] + a[i];

    for(ll i = 1;i * i <= pref[n];i++){
        if(pref[n] % i == 0)no.push_back(i),no.push_back(pref[n]/i);
    }
    ll ans = 0;

    for(ll i = 0;i<no.size();i++){
        ll x = no[i];
        bool cs = 0;
        ll d = 0;
        while(x <= pref[n]){
            if(binary_search(pref + 1,pref + 1 + n,x)){
                d++;
            }else {
                cs = 1;
                break;
            }
            x += no[i];
        }
        if(!cs && ans < d)ans = d ;
    }

    cout<<ans;

    
    
}