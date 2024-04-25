#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    vector<ll>ans;
    for(ll i = 1;i<=99;i++){
        ans.push_back(i);
        ans.push_back(i*100);
        ans.push_back(i*1e4);
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<' ';
}
