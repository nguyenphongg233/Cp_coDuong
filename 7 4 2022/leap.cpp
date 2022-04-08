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


pair<ll,ll> maxx[MAX];
ll n,q;
ll a[MAX];
ll dp[MAX];
vi once;
// dp[i] : ngay xuat phat thu i

signed main(){

    cin>>n>>q;
    for(ll i = 1;i <= n;i++){
        cin>>a[i];
        if(i == 1)maxx[i] = {a[1],1},once.push_back(1);
        else{
            if(a[i] > maxx[i-1].X){
                maxx[i] = {a[i],i};
                once.push_back(i);
            }else{
                maxx[i] = maxx[i-1];
            }
        }
    }

    /*for(ll i = 1;i <= n;i++){
        cout<<maxx[i].X<<" "<<maxx[i].Y<<"\n";
    }*/
    once.push_back(n + 1);
    dp[n + 1] = -1;
    dp[n] = 0;
    for(ll i = n - 1;i > 0;i--){
        ll x = i;
        ll cs = lower_bound(once.begin(),once.end(),i) - once.begin();
        //if(cs == -1)cs++;

        if(once[cs] == x && cs < once.size()){
            dp[i] = dp[once[cs + 1]] + 1;
            //cout<<i<<" AC \n";
        }else{
            while(x <= n && a[i] >= a[x]){
                x++;
            }
            dp[i] = dp[x] + 1;
            //cout<<i<<" WA \n";
        }
    }

    //for(ll i = 1;i <= n;i++)cout<<dp[i]<<" ";

    cout<<"\n";

    while(q--){
        ll x;cin>>x;
        //cout<<"ans =";
        cout<<dp[x]<<"\n";
    }


    
    
}