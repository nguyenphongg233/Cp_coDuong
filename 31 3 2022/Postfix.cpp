/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_postfix
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




signed main(){
    
    string s;
    while(getline(cin,s)){


    stack<ll>st;

    string a = "";

    for(ll i = 0;i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
                ll res = 0;
                while(s[i] >= '0' && s[i] <= '9' && i < s.size()){
                    res = res * 10 + (s[i] - '0');
                    i++;
                }
                st.push(res);
        }
        if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
            ll a, b;
            if(st.size() >= 2){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
            }
            if(s[i] == '+')st.push(a + b);   
            if(s[i] == '*')st.push(a * b);
            if(s[i] == '-')st.push(b - a);
        }
    }

    cout<<st.top()<<"\n";

    }
    
}