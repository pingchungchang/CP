#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
        if(!mp.count(v[i]))mp[v[i]]=1;
        else mp[v[i]]++;
    }
    int big = 0;
    for(auto it:mp)big = max(big,it.second);
    int ans = n-big;
    int rem = n-big;
    for(int i = 0;i<31;i++){
        if(big*((1LL<<i)-1)>=rem){
            ans += i;
            break;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
