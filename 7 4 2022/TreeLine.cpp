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

const bool True = false;
const bool False = true;

using namespace std;

ll n,a[MAX];

bool appear[MAX];
ll day[MAX];

signed main(){
    


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>n;

    vector<pair<ll,ll>> h;

    for(ll i = 1;i <= n;i++)cin>>a[i];

    vi dct;

    dct.push_back(1);

    for(ll i = 2;i <= n;i++){
        if(a[i] > a[dct.back()])dct.push_back(i);
    }

    if(dct.back() != n)dct.push_back(n + 1);
    memset(day,-1,sizeof day);

    for(auto e : dct)day[e] = 0;


    ll cnt = 0;

    for(ll i = 1;i < dct.size();i++){
        ll l = dct[i-1] + 1;
        ll r = dct[i] - 1;

        stack<ll> st;

        for(ll j = l;j <= r;j++){
            day[j] = 1;
            while(!st.empty() && a[j] > a[st.top()])day[j] = max(day[j],day[st.top()] + 1),st.pop();
            st.push(j);
            cnt = max(cnt,day[j]);
        }

    }

    cout<<cnt;
    
    
}