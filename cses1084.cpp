#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll people[n];
    multiset<ll> dep;
    for(ll i =0;i<n;i++)cin>>people[i];
    for(ll i =0;i<m;i++){
        ll j;
        cin>>j;
        dep.insert(j);
    }
    ll ans =0;
    sort(people,people+n);
    for(ll i =0;i<n;i++){
        if(dep.size()==0)break;
        auto it = dep.lower_bound(people[i]-k);
        //cout<<i<<' '<<*it<<endl;
        if(it == dep.end())continue;
        else if(*it>people[i]+k){
            continue;
        }
        else{
            ans++;
            dep.erase(it);
        }
    }
    cout<<ans;
}
