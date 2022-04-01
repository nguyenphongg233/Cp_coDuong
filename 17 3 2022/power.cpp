#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second
const long long MAX = 10;
const long long mod = 1e9 + 7;

using namespace std;


int n,k;
map<int,int> m;
int a[100],b[100];


signed main(){

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        m[x] = 1;
    }


    for(int i = 1; i <= 43; i++)b[i] = 0;



    for(auto x:m){
        for(int i = 1; i <=43; i++){
            a[i] = 0;
        }
        int i = 2;
        int M = x.X;
        while(M!=1){
            if(M%i==0)M/=i,a[i]++;
            else i++;
        }

        for(int i = 1; i <=43; i++){
            b[i] = max(b[i],a[i]);
        }

    }

    for(int i = 1; i <= 43; i++){
        if(b[i]>0){
            if(b[i]%k==0)b[i]/=k;
            else b[i] = b[i]/k+1;
        }
    }
    int ans = 1;
    for(int i = 1; i <= 43; i++){
        if(b[i]>0)ans*=pow(i,b[i]);
    }
    cout << ans;
    return 0;
}