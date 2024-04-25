#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
int n;
ll s;
bool f(ll val){
    ll total = 0;
    for(auto i:v){
        if(i<val)return false;
        total += i-val;
    }
    if(total>=s)return true;
    else return false;
}
int main(){
    cin>>n>>s;
    v = vector<ll> (n);
    for(int i = 0;i<n;i++)cin>>v[i];
    ll l = 0, r = 1e9+3;
    ll sum = 0;
    for(auto i:v)sum += i;
    if(sum<s){
        cout<<-1;
        return 0;
    }
    while(l != r){
        ll mid = (l+r+1)/2;
        if(f(mid)){
            l = mid;
        }
        else r = mid-1;
    }
    cout<<r;
}
