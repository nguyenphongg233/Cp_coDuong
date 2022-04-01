/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_lineup
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


ll a[MAX];

signed main(){
    
    
    ll n;

    cin>>n;

    stack <ll> st;
    for(ll i = 0,x;i<n;i++){
        cin>>a[i];
        while(!st.empty() && a[st.top()] <= a[i])st.pop();

        if(st.size())cout<<st.top()<<" ";
        else cout<<-1<<" ";
        st.push(i);
    }
    
}
/// 9
/// 30 20 10 40 90 50 40 60 70