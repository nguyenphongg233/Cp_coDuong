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


//FIFO

signed main(){
    
    ll n;
    cin>>n;

    stack<ll> st;

    while(n > 0){
        st.push(n%2);
        n/=2;
    }

    while(st.size()){
        cout<<st.top();
        st.pop();
    }

    
    
    
    
}