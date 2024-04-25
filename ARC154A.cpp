#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
int main(){
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    for(int i = 0;i<n;i++){
        if(a[i]<b[i])swap(a[i],b[i]);
    }
    ll ta = 0,tb = 0;
    ll p = 1;
    for(int i = n-1;i>=0;i--){
        ta = (ta+p*(a[i]-'0'))%mod;
        tb = (tb+p*(b[i]-'0'))%mod;
        p  =p*10%mod;
    }
    cout<<ta*tb%mod;
}