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
ll a[MAX];
deque<ll> h;


signed main() {

		cin >> n >> k;
		vi a(n + 1);
		for(ll i = 1;i <= n;i++)cin >> a[i];
		deque<ll> dq;
		dq.clear();
		ll minRange[MAX];
		for(ll i = 1;i <=n;i++) {
			while (dq.size() && a[dq.back()] >= a[i])dq.pop_back();
			dq.push_back(i);
			if (dq.front() + k <= i)dq.pop_front();
			if (i >= k)minRange[i] = a[dq.front()];
		}
		for(ll i = k;i<=n;i++)cout << minRange[i] << " ";
		cout << "\n";
}
