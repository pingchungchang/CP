#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> pref;

ll sum(ll s,ll e){
    if(s<=0)return pref[e];
    else return pref[e]-pref[s-1];
}
int main(){
    ll n,k;
    cin>>n>>k;
    pref = vector<ll>(n,0LL);
    ll arr[n];
    for(ll i = 0;i<n;i++)cin>>arr[i];
    pref[0] = arr[0];
    for(ll i = 1;i<n;i++){
        pref[i] = arr[i];
        pref[i] += pref[i-1];
    }
    cout<<arr[0]*k<<' ';
    ll now = arr[0]*k;
    for(ll i = 1;i<n;i++){
        now -= sum(i-k,i-1);
        now += k*arr[i];
        cout<<now<<' ';
    }
}
