#include<bits/stdc++.h>

#define int long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define getbit(x,n) ((x >> n) & 1);
#define turnoff(x,n) (x & ~(1 << n));
#define turnon(x,n) (x | (1<<n))

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 305;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

int n,m,a[MAX][MAX],f[MAX][MAX],sum[MAX][MAX];


signed main(void){
    faster();
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++)cin >> a[i][j];
    }
    for(int j = 1; j <= n; j++)sum[0][j]=0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i-1][j]+a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){ 
        for(int j = 1; j+i-1 <= m; j++){ 
            int dem = 0;
            for(int t = 1; t <= n; t++){
                if((sum[j+i-1][t]-sum[j-1][t])==0&&t==n){
                    dem++;
                    for(int d = 1; d <= dem; d++){
                        f[i][d]+=dem-d+1;
                    }
                }
                else if((sum[j+i-1][t]-sum[j-1][t])==0)dem++;
                else{
                    if(dem == 0)continue;
                    for(int d = 1; d <= dem; d++){
                        f[i][d]+=dem-d+1;
                    }
                    dem = 0;
                }
            }
            dem = 0;
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}