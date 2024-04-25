#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(pair<int,int> a,pair<int,int>b){
        if(a.first!=b.first)return a.first>b.first;
        else return a.second>b.second;
    }
};
int main(){
    int n;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>, Compare> pq;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pq.push(make_pair(a,b));
    }
    while(!pq.empty()){
        pair<int,int> now = pq.top();
        printf("%d %d\n",now.first,now.second);
        pq.pop();
    }
}