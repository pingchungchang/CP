#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,t;
    cin>>n>>t;
    ll arr[n];
    ll total = 0;
    for(auto &i:arr){
        cin>>i;
        total += i;
    }
    t %= total;
    for(int i = 0;i<n;i++){
        if(arr[i]>t){
            cout<<i+1<<' '<<t;
            return 0;
        }
        t -= arr[i];
    }
    return 0;
}