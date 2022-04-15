#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 105;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};


using namespace std;



signed main(){
	
	
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll sir[MAX];
		ll a[MAX][MAX];
		ll cost[MAX];
		for(ll i = 1;i <= n;i++){
			cin>>sir[i];
			for(ll j = 1;j <= sir[i];j++)cin>>a[i][j];
			cin>>cost[i];
		}
		ll tic[MAX];
		for(ll i = 1;i <=m;i++)cin>>tic[i];
		ll res = 0;
		for(ll i = 1;i <= n;i++){
			ll minx = INF;
			for(ll j = 1;j <= sir[i];j++){
				minx = min(minx,tic[a[i][j]]);
			}
			res += minx * cost[i];
		}
		cout<<res<<"\n";
	}
	
}
