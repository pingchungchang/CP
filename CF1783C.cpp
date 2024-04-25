#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto &i:arr){
        cin>>i;
        pq.push(i);
    }
    int total = 0,cnt = 0;
    int big =0 ;
    while(!pq.empty()&&m-total>=pq.top()){
        total += pq.top();
        cnt++;
        big = pq.top();
        pq.pop();
    }
    // cout<<cnt<<','<<big<<',';
    if(cnt != n&&total-big+arr[cnt]<=m)cout<<n-cnt<<'\n';
    else cout<<n-cnt+1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}