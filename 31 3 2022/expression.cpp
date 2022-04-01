/*
  Link Problem : https://oj.vnoi.info/problem/cnhhn_expression
*/
#include<bits/stdc++.h>

#define ll long long
#define vi vector<ll>

#define X first
#define Y second

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;

const bool True = false;
const bool False = true;

using namespace std;




stack<char> v;
stack<int> so;

int gcd(int a, int b){
    a = abs(a);
    b = abs(b);

    while(a != b){
        if(a < b)b-=a;
        else a-=b;
    }

    return a;
}

signed main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int i = 0;
    while(i<s.size()){
        if(s[i]=='S')v.push('s'),i+=4;
        else if(s[i]=='D')v.push('d'),i+=4;
        else if(s[i]=='G')v.push('g'),i+=4;
        else if(s[i]=='M'&&s[i+1]=='I')v.push('n'),i+=4;
        else if(s[i]=='M'&&s[i+1]=='A')v.push('x'),i+=4;
        else if(s[i]>='0'&&s[i]<='9'){
            string ans = "";
            while(s[i]>='0'&&s[i]<='9')ans += s[i],i++;
            so.push(stol(ans));
        }
        else if(s[i]==')'){
            char cayvcl = v.top();
            v.pop();
            int x1 = so.top();
            so.pop();
            int x2 = so.top();
            so.pop();
            if(cayvcl == 's')so.push(x1+x2);
            else if(cayvcl == 'd')so.push(-x1+x2);
            else if(cayvcl == 'g')so.push(gcd(x1,x2));
            else if(cayvcl == 'n')so.push(min(x1,x2));
            else if(cayvcl == 'x')so.push(max(x1,x2));
            i++;
        }
        else i++;
    }
    cout << so.top();
    #ifndef LOCAL_DEFINE
        cerr << "\nTime elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";
    #endif
    return 0;
}