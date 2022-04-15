#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,k,a[MAX];

signed main(){
    
    cin>>n>>k;

    for(ll i = 1;i <= n;i++)
        cin>>a[i];
    
    deque<ll> h;

    ll sum = 0;

    for(ll i = 1;i <= n;i++){
        while(h.size() && a[i] <= a[h.back()])h.pop_back();
        while(h.size() && h.front() <= i - k)h.pop_front();
        h.push_back(i);

        
        sum += a[h.front()];
    }

    cout<<sum;
    
    
    
}