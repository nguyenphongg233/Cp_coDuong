/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_dn
*/
#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

const bool True = false;
const bool False = true;

//  code là cái gì ?

using namespace std;




signed main(){
    faster();
    



    string s;

    cin>>s;

    stack<ll> st;

    for(ll i = 0;i<s.size();i++){
        if(s[i] == '(')st.push(i);
        else cout<<st.top()<<" ",st.pop();
    }



    /*stack<ll> s;
    for(ll i = 1;i<=100;i++)s.push(i);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }*/
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}