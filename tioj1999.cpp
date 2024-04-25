#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        if(pq.size()<m){
            pq.push(k);
        }
        else{
            pq.push(k+pq.top());
            pq.pop();
        }
    }
    int ans = 0;
    while(pq.size()>1){
        pq.pop();
    }
    cout<<pq.top();
}
