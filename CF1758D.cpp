#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n&1){
        vector<int> v = {n};
        for(int i = 1;i<=n/2;i++){
            v.push_back(n-i);
            v.push_back(n+i);
        }
        sort(v.begin(),v.end());
        for(auto &i:v)i += 2;
        v[0]--;
        v.back()++;
        v[v.size()-2]++;
        for(auto &i:v)cout<<i<<' ';cout<<'\n';
    }
    else{
        for(int i = n/2;i<=3*n/2;i++){
            if(i == n)continue;
            cout<<i<<' ';
        }
        cout<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}