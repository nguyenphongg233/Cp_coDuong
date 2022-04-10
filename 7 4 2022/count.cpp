/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_count
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

const bool True = false;
const bool False = true;

using namespace std;

ll n,a[MAX],q;

signed main(){
    
    cin>>q;

    while(q--){
        cin>>n;

        for(ll i = 1;i <= n;i++)cin>>a[i];

        stack<ll> st;

        ll left[MAX];
        for(ll i = 1;i <= n;i++){
            if(st.empty()){
                left[i] = 0;
                st.push(i);
            }else{
                while(!st.empty() && a[st.top()] < a[i])st.pop();
                if(st.empty()){
                   left[i] = 0;
                   st.push(i);
                }else if(a[st.top()] == a[i]){
                    left[i] = left[st.top()] + 1;
                    st.push(i);
                }else{
                    left[i] = 0;
                    st.push(i);
                }
            }
        }


        while(st.size())st.pop();

        ll right[MAX];
        for(ll i = n;i > 0;i--){
            if(st.empty()){
                right[i] = 0;
                st.push(i);
            }else{
                while(!st.empty() && a[st.top()] < a[i])st.pop();
                if(st.empty()){
                   right[i] = 0;
                   st.push(i);
                }else if(a[st.top()] == a[i]){
                    right[i] = right[st.top()] + 1;
                    st.push(i);
                }else{
                    right[i] = 0;
                    st.push(i);
                }
            }
        }

        for(ll i = 1;i <= n;i++)cout<<left[i] + right[i]<<" ";
        cout<<"\n";
    }
    
    
    
}