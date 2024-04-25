#include <bits/stdc++.h>
using namespace std;


vector<int> v;
int n;

bool f(int val){
    int total = 0;
    for(auto i:v){
        if(i>val)total += i-val;
    }
    if(total>val)return false;
    else return true;
}
void solve(){
    cin>>n;
    v = {};
    priority_queue<int,vector<int>,less<int>> pq;
    vector<int> nodes(n,0);
    for(int i = 0;i<n-1;i++){
        int k;
        cin>>k;
        k--;
        nodes[k]++;
    }
    pq.push(1);
    for(auto i:nodes){
        if(i != 0)pq.push(i);
    }
    int pre = pq.size();
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        if(now-pq.size()-1>0)v.push_back(now-pq.size()-1);
        else continue;
    }
    int l = 0;
    int r = 200010;
    while(l != r){
        int mid = (l+r)/2;
        if(f(mid)){
            r = mid;
        }
        else l = mid+1;
    }
    cout<<l+pre<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
