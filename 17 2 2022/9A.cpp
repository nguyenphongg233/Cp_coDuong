#include<bits/stdc++.h>

#define ll int
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 205;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

ll a[MAX],n,c;
ll dp[205][170000];
ll add = 40001;

signed main() {
	faster();
	ll t;cin >> t;
	while(t--) {
		cin >> n >> c;
		ll minn = 0,maxx = 0;
		for (ll i = 1;i<=n;i++) {
			cin >> a[i];a[i] -= c;
			if (a[i] < 0) minn = minn + a[i];
	    	else if (a[i] > 0) maxx = maxx + a[i];
		}
		 for (ll i = 1; i <= n; i++) {
        	for (ll j = minn; j <= maxx; j++) {
            	dp[i][j + add] = (dp[i - 1][j + add] + dp[i - 1][j - a[i] + add]) % mod;
       		}
       		dp[i][a[i] + add] = (dp[i][a[i] + add] + 1) % mod;
    	}
		cout << dp[n][add] % mod << "\n";
		for (ll i = 1;i<=n;i++) {
			for (ll j = minn;j<=maxx;j++) {
				dp[i][j + add] = 0;
				dp[i][a[i] + add] = 0;
			}
		}
		
	}


	return 0;
}