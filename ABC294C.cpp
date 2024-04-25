#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        v.push_back({k,i});
    }
    for(int i = 1;i<=m;i++){
        int k;
        cin>>k;v.push_back({k,-i});
    }
    sort(v.begin(),v.end());
    int ans1[n+1],ans2[m+1];
    for(int i = 0;i<v.size();i++){
        if(v[i].second>0)ans1[v[i].second] = i+1;
        else ans2[-v[i].second] = i+1;
    }
    for(int i = 1;i<=n;i++)cout<<ans1[i]<<' ';cout<<'\n';
    for(int i = 1;i<=m;i++)cout<<ans2[i]<<' ';cout<<'\n';
}