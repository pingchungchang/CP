#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t,n;
    cin>>t>>n;
    vector<ll>all(n);
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        cin>>all[i];
        sum += all[i];
    }
    for(ll i = 0;i<n;i++){
        cout<<fixed<<setprecision(1)<<t*(long double)(all[i])/sum<<' ';
    }
}
