#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FOD(i, a, b) for (ll i = a; i >= b; i--)

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

// Author : NguyenPhongg
// Date : 22 1 2022
// NT --> NH --> NU 

using namespace std;

ll x,y,a[1005],ans = 0;

signed main(){
    faster();
    cin>>x>>y;
    FOR(i,1,x) cin >> a[i];
    FOR(i,2,x) a[i]=a[i]-y*(i-1);
    sort(a+1,a+x+1);
    ll k = a[(x+1)/2];
    FOR(i,1,x) ans+=abs(k-a[i]);
    cout << ans;
    return 0;
}