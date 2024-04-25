#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll b;
    string s;
    cin>>b>>s;
    ll total = 0;
    ll n = s.size();
    for(auto &i:s){
        ll tmp = n;
        ll k = 1;
        while(tmp--){
            k *= (i-'0');
        }
        total += k;
    }
    ll p = 1;
    ll t2 = 0;
    for(int i = n-1;i>=0;i--){
        t2 += p*(s[i]-'0');
        p *= b;
    }
    if(total == t2)cout<<"YES";
    else cout<<"NO";
}