#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ans = 1e18;
ll n,a,b;

ll calc(string &s){
    ll re = 0;
    for(int i = 0;i<n;i++){
        if(s[i] != s[n-1-i]){
            re += b;
            s[i] = s[n-1-i];
        }
    }
    return re;
}
int main(){
    cin>>n>>a>>b;
    string s;
    cin>>s;
    for(int i = 0;i<n;i++){
        string ss = s.substr(i,s.size()-i)+s.substr(0,i);
        ans = min(ans,calc(ss)+i*a);
    }
    cout<<ans;
}