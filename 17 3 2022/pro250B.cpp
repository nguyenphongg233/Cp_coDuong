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


ll n,len,pdt = 0,k,num = 1;
string smp[10];
ll a[MAX];
string s;


signed main(){
    faster();

    cin>>n;

    while(n--){
		cin>>s;
		len=s.size();
		memset(a,0,sizeof(a));
		for(ll i=1; i<=8 ;i++) smp[i]="";

		pdt=1;
        num=1;
        k=9;

		for(ll i=0;i<len;i++){
			if(s[i]!=':') smp[pdt].push_back(s[i]);
			else{
				if(i==0)    k=1;
				else if(s[i-1]==':')k=pdt;
				else if(i!=len-1)a[pdt]=smp[pdt].size(),pdt++; 
			}
		}


		a[pdt] = len(smp[pdt]);
		if(a[pdt] == 0) pdt--;

		for(ll i = 1; i <= 8 ;i++){
			if(i == k) {
				for(ll j=0;j<=8-pdt-1;j++) {
					if(i+j==8)cout<<"0000";
					else cout<<"0000:";
				}
				i += 7-pdt;
			}
			else{
				if(i!=8){
					for(ll j=1;j<=4-a[num];j++) cout<<"0";
					cout<<smp[num]<<":";
                    num++;
				}
				else{
					for(ll j=1;j<=4-a[num];j++)cout<<"0";
					cout<<smp[num];
				}   
			}
			
		}
        
		cout<<"\n";
	}
    
    
    
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}