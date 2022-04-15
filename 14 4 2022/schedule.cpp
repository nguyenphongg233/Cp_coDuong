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

ll n;
ii a[MAX];

bool cmp(ii a,ii b){
    
    return (a.Y) * (a.X)  + (b.Y + a.Y) * b.X< b.Y * b.X + (b.Y + a.Y) * a.X;
}

signed main(){
    
    cin>>n;
    for(ll i = 1;i <= n;i++)cin>>a[i].X;
    for(ll i = 1;i <= n;i++)cin>>a[i].Y;
    
    sort(a + 1 ,a + 1 + n,cmp);

    //for(ll i = 1;i <= n;i++)cout<<a[i].X<<" "<<a[i].Y<<"\n";
    ll sum = 0;
    ll day = 0;
    for(ll i = 1;i <= n;i++)day += a[i].Y,sum += day * a[i].X;

    cout<<sum;
    
    
}
