#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    priority_queue<int,vector<int>,less<int>> pq;
    for(auto &i:arr)pq.push(i);
    int total = 0;
    int cnt[n+1] = {};
    for(auto &i:arr){
        cnt[abs(i)]++;
    }
    while(!pq.empty()){
        total += (pq.top()>0?1:-1);
        pq.pop();
        cout<<total<<' ';
    }
    cout<<'\n';
    vector<int> ans = {0};
    for(int i = 1;i<=n;i++){
        if(cnt[i] == 2){ans.push_back(ans.back()+1);ans.push_back(ans.back()-1);}
    }
    while(ans.size()<n+1)ans.push_back(ans.back()+1);
    for(int i= 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}