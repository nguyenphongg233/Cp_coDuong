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

ll n,m,cnt = 0;

struct ex{
    ll x,xt;
    bool a;
}s[MAX];

bool cmp(ex &a,ex &b){
    if(a.x == b.x)return a.a > b.a;
    else return a.x < b.x;
}

bool appear[MAX];

signed main(){
    
    cin>>n>>m;
    
    for(ll i = 1,u,v;i <= m;i++){
        cin>>u>>v;

        s[i * 2 - 1] = {u,i,1};
        s[i * 2] = {v,i,0};

    }


    stack<ll> st;

    sort(s + 1,s + 1 + 2 * m,cmp);
    for(ll i = 1;i <= 2 * m;i++){
        ll x = s[i].x;
        ll xt = s[i].xt;
        bool a = s[i].a;

        if(a)st.push(xt);
        else{
            if(appear[xt])continue;
            cnt++;

            while(!st.empty()){
                appear[st.top()] = 1;
                st.pop();
            }
        }
    }

    cout<<cnt;
}