#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    scanf("%lld\n",&a);
    for(ll i = 0;i<a;i++){
        ll n;
        scanf("%lld",&n);
        if(i != a-1)scanf(" ");
        pq.push(n);
    }
    printf("%lld",pq.top());
}