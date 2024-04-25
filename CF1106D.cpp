#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n);
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<bool> goneto(n,false);
    vector<int> ans;
    for(int i  =0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a == b)continue;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0;i<n;i++){
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
    }
    goneto[0] = true;
    pq.push(0);
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        ans.push_back(now+1);
        for(auto nxt:v[now]){
            if(goneto[nxt] == false){
                pq.push(nxt);
                goneto[nxt] = true;
            }
        }
    }
    for(auto i:ans)cout<<i<<' ';

}
