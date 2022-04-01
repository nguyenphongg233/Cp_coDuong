#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

string a,b;
ll pref[MAX];

signed main(){
    
    cin>>a>>b;

    if(a == b)return cout<<1<<' '<<1,0;
    ll n = a.size();
    ll m = b.size();

    a = " " + a;
    b = " " + b;

    pref[0] = 0;

    for(ll i = 1;i<=n;i++){
        pref[i] = pref[i-1] + a[i] - '0';
    }
    pair<ll,ll> ans = {INF,0};
    ll lengthh = 0;
    for(ll i = 1;i<=7;i++){
        for(ll j = 1;j + i - 1 <= m;j++){
            string c = b.substr(j,i);
            ll str = j;
            ll ed = m - (i + j - 1);
            ed = n-ed;
            //cout<<str<<" "<<ed<<" ";
            //cout<<pref[ed] - pref[str - 1]<<" "<<c<<"\n";
            if(str < ans.X && stol(c) == pref[ed] - pref[str - 1] && lengthh == ed - str + 1)ans = {str,ed};
            if(lengthh < ed - str + 1 && stol(c) == pref[ed] - pref[str - 1])ans = {str,ed},lengthh = ed - str + 1;
        }
    }
    
    cout<<ans.X <<" "<<ans.Y <<'\n';
    
}