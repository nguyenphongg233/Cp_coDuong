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

ll n, p;
ll id[MAX];
deque<ll> dmin, dmax;
signed main() {
	
    cin>>n>>p;
    for(ll i = 1; i <=n; i++) cin>>id[i];

    ll maxlen = 1, pos = 0;

    for(ll i = 1; i <= n; i++){

        while(!dmin.empty() && id[dmin.back()]>id[i]) dmin.pop_back();  
        dmin.push_back(i);

 
        while(!dmax.empty() && id[dmax.back()]<id[i]) dmax.pop_back();
        dmax.push_back(i);


        while(!dmin.empty() && !dmax.empty()){
            if(id[dmax.front()] - id[dmin.front()]<=p){
                maxlen = max(maxlen, i-pos);
                break;
            }
            if (dmin.front() > dmax.front()){
                pos = dmax.front();
                dmax.pop_front();
            }else{
                pos = dmin.front();
                dmin.pop_front();
            }
        }
    }

    cout<<maxlen;
    return 0;
}
