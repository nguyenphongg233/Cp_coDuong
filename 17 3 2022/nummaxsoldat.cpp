#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define matrix vector<vector<long long>>

const long long INF = 2000000000000000000LL;
const long long mod = 123456789;
const long long K = 10000000;

//🏅 🤡

int n,b;
int a[100005];
int f[100005];
vector<int> v;
vector<int> lon;
long long ans = 0;


signed main(void){
    ll n;
    cin>>n;

    vector<ll> no;
    for(ll i = 1;i * i <= n;i++){
        if(n%i == 0){
            no.push_back(i);
            if(n/i != i)no.push_back(n/i);
        }
    }
    cout<<no.size();
}