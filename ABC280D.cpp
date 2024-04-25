#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cnt(ll k,ll x){
    ll re = 0;
    ll tmp = x;
    while(tmp<=k){
        re += k/tmp;
        tmp *=x;
    }
    return re;
}
int main(){
    ll k;
    cin>>k;
    ll l = 1,r = k;
    map<ll,ll> fac;
    while(k!= 1){
        bool flag = false;
        for(ll i = 2;i*i<=k;i++){
            if(k%i == 0){
                flag = true;
                fac[i]++;
                k/=i;
                break;
            }
        }
        if(!flag){
            fac[k]++;
            k = 1;
        }
    }
    while(l != r){
        ll mid = (l+r)>>1;
        bool flag = true;
        for(auto &i:fac){
            if(cnt(mid,i.first)<i.second)flag = false;
        }
        if(flag)r = mid;
        else l = mid+1;
    }
    cout<<l;
}