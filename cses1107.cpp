#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    multiset<ll> l;
    multiset<ll> r;
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    ll mid;
    ll sum = 0;
    for(int i = 0;i<k;i++){
        l.insert(v[i]);
        sum += v[i];
    }
    while(l.size()>r.size()){
        r.insert(*l.rbegin());
        l.erase(l.rbegin());
    }
    mid = *r.begin();
}
