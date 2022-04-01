#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ce(x) cerr << #x << " = " << x << endl
#define len(x) x.size();

#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1e6 + 5;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;



int a[MAX],n,b[MAX];
signed main() {
	faster();
	cin >> n;
	for (ll i = 1;i<=n;i++) cin >> a[i];
	ll q;
	cin >> q;
	while(q--) {
		int l,r,x;
		cin >> l >> r >> x;
		b[l] += x;
		b[r+1] -= x;
	}
	for (int i = 2;i<=n;i++) b[i] += b[i-1];
	for (int i = 1;i<=n;i++) cout << a[i] + b[i] << " ";
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
	return 0;
}
