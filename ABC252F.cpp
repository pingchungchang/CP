#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll ans = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll n,L;
    cin>>n>>L;
    for(ll i= 0;i<n;i++){
        ll k;
        cin>>k;
        pq.push(k);
        L -= k;
    }
    if(L != 0)pq.push(L);
    while(pq.size()>1){
        ll a = pq.top();pq.pop();ll b = pq.top();pq.pop();
        ans += a+b;
        pq.push(a+b);
        //cout<<a<<' '<<b<<' '<<endl;
    }
    cout<<ans;
}
