#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<int,int> mp;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        mp[k]++;
    }
    int ans= 0;
    for(auto &i:mp)ans += i.second/2;
    cout<<ans;
}