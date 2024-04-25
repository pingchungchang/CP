#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    while(scanf("%lld",&n)){
        if(n == 0)return 0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i =0;i<n;i++){
            ll k;
            scanf("%d",&k);
            pq.push(k);
        }
        ll ans = 0;
        while(pq.size()>=2){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ans += a+b;
            pq.push(a+b);
        }
        printf("%lld\n",ans);
    }
}
