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
const long long  MAX = 1e7+5;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

int t;
bool f[MAX];
int to_int(string n) {
	int ans = 0, p = 1;
	for (int i = n.size() - 1; i >= 0; i--) {
		ans += p * (n[i] - 48);
		p *= 10;
	}
	return ans;
}

signed main(void) {
    faster();
    fill_n(f, MAX, true);
	f[0] = f[1] = false;
	for (int i = 2; i * i < MAX; i++)
		if (f[i])
			for (int j = i * i; j < MAX; j += i) f[j] = false;
    cin >> t;
    while (t--) {
    	string n; cin >> n;
    	int kq = 0;
    	sort(n.begin(), n.end());
    	map<int, bool> check;
    	do {
    		for (int i = 0; i < n.size(); i++)
    			for (int j = 1; j + i <= n.size(); j++) {
    				int a = to_int(n.substr(i, j));
    				if (f[a] && !check[a]) kq++;
    				check[a] = true;
    			}
    	} while (next_permutation(n.begin(), n.end()));
    	cout << kq << "\n";
    }
    
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    
    return 0;
}
 