#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n){
        if(n==0)return 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        for(int i =0;i<n;i++){
            int a,b;
            cin>>a>>b;
            pq.push(make_pair(b,a));
        }
        int nowtime = 0;
        int ans = 0;
        while(!pq.empty()){
            nowtime+= pq.top().second;
            ans = max(ans,nowtime+pq.top().first);
            pq.pop();
        }
        cout<<ans<<'\n';
    }
}
