#include<bits/stdc++.h>

#define ll long long;

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;

using namespace std;

string s;
int n,a[MAX];


signed main(){
    
    cin>>s;
    n = s.size() + 1;
    s = " " + s;
    for(int i = 1;i<=n;i++)a[i] = i;
    
    int str = -1;

    for(int i = 1;i<=n;i++){
        //cout<<a[i]<<" "<<s[i]<<" "<<str<<" \n";
        if(s[i] == '<' && str != -1){
            reverse(a + str,a + i + 1);
            str = -1;
        }else if(s[i] == '>' && str == -1)str = i;
        else continue;
    }
    if(str != -1)reverse(a + str,a + 1 + n);
    for(int i = 1;i<=n;i++)cout<<a[i]<<" ";
}