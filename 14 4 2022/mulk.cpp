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
const long long  MAX = 1000005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};


using namespace std;

ll n,k;

signed main(){
	
	cin>>n>>k;
	
	ll res = n/k;
	
	res = (res * (res) * (res));
	
	//cout<<res<<"\n";
	
	if(k & 1)return cout<<res,0;
	
	ll d = 0;
	
	for(ll i = k/2;i <= n;i += k)d++;
	
	cout<<res + d * d * d;
	
	
		
}
