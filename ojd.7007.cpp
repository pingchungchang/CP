#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,s;
    cin>>n>>s;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    ll small = s,big = s;
    for(auto &i:arr){
        small = min(small,i);
        big = max(big,i);
        cout<<big-small+min(s-small,big-s)<<'\n';
    }
    return 0;
}