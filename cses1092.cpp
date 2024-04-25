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
    if(sum&1==1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    vector<vector<ll>> arr(2);
    sum /=2;
    for(ll i =n;i>=1;i--){
        if(sum>=i){
            arr[0].push_back(i);
            sum -=i;
        }
        else{
            arr[1].push_back(i);
        }
    }
    cout<<arr[0].size()<<'\n';
    for(ll i = arr[0].size()-1;i>=0;i--){
        cout<<arr[0][i];
        if(i != 0)cout<<' ';
    }
    cout<<'\n';
    cout<<arr[1].size()<<'\n';
    for(ll i =arr[1].size()-1;i>=0;i--){
        cout<<arr[1][i];
        if(i != 0)cout<<' ';
    }
}
