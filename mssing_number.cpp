#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    for(ll i =0;i<n-1;i++){
        ll k;
        cin>>k;
        sum -=k;
    }
    cout<<sum;
}
