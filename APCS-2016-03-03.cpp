#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(pair<int,int>p1,pair<int,int>p2){
        if(p1.first!=p2.first)return p1.first>p2.first;
        else return p1.second>p2.second;
    }
};
int main(){
    int n;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pq.push(make_pair(a,b));
    }
    int now = 0;
    int ans = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        if(p.first<now){
            p.first = now;
        }
        if(p.second<=now)continue;
        ans+=p.second-p.first;
        now = p.second;
    }
    cout<<ans;
}