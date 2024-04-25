#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        pq.push(k);
    }
    int total = 0;
    int ans = 0;
    while(total<m&&!pq.empty()){
        total += pq.top();pq.pop();
        ans ++;
    }
    if(total>=m)cout<<ans;
    else cout<<"OAQ";
}
