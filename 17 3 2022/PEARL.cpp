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
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;


ll n, m, a[MAX];
vi tree[MAX * 4];
ll pre[MAX];
map<ll,ll> mp;

void buildtree(ll id, ll l, ll r) {
	if (l == r) {
		tree[id].push_back(pre[l]);
		return;
	}
	ll m = (l + r) / 2;
	buildtree(id * 2, l, m);
	buildtree(id * 2 + 1, m + 1, r);
	tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
	merge(tree[id * 2].begin(), tree[id * 2].end(), tree[id * 2 + 1].begin(), tree[id * 2 + 1].end(), tree[id].begin());
}
ll getval(ll id, ll l, ll r, ll u, ll v, ll k) {
	if (u > r || v < l)return 0;
	if (u <= l && v >= r) return lower_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin();
	ll m = (l + r) / 2;
	return getval(id * 2, l, m, u, v, k) + getval(id * 2 + 1, m + 1, r, u, v, k);
}

signed main(){
    faster();

    cin>>n;

	for(ll i = 1;i<=n;i++) {
	    cin >> a[i];
		pre[i] = mp[a[i]];
		mp[a[i]] = i;
	}

    buildtree(1,1,n);


    vi no;
    for(ll i = 1;i * i <= n;i++){
        if(n%i == 0){
            no.push_back(i);
            if(n/i != i)no.push_back(n/i);
        }
    }

    sort(no.begin(),no.end());

    cout<<no.size()<<'\n';

    for(auto x : no){
        cout<<x<<" ";
        ll ans = INF;
        if(x == 1){
            cout<<1<<"\n";
            continue;
        }
        for(ll i = 1;i <= n - x + 1;i = i + x - 1){
            //cout<<i<<" "<<i + x - 1<<" : ";
            ans = min(ans,getval(1,1,n,i,i + x - 1,i));
            //cout<<getval(1,1,n,i,i + x - 1,i)<<"\n";
        }
        cout<<ans<<'\n';
    }
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}