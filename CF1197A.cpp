#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        pq.push(k);
    }
    pq.pop();
    int k = pq.top();
    pq.pop();
    cout<<min(k-1,(int)pq.size())<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
