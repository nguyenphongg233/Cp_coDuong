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

ll n,m;
vi adj[MAX];
signed main(){
	cin>>n>>m;
	
	for(ll i = 1,u,v;i <= m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	queue<ll> h;
	
	h.push(0);
	ll step[MAX];
	step[0] = 0;
	bool visited[MAX];
	
	memset(visited,0,sizeof visited);
	visited[0] = 1;
	while(!h.empty()){
		ll u = h.front();
		h.pop();
		if(u == n - 1)return cout<<step[u],0;
		
		for(auto e : adj[u]){
			if(!visited[e])h.push(e),visited[e] = 1,step[e] = step[u] + 1;
		}
	}
	
	cout<<-1;
}
