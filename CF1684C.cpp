#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    pair<int,int> ans = make_pair(-1,-1);
    vector<vector<int>> v(n,vector<int>(m));
    int now = 0;
    for(int i = 0;i<n;i++){
        vector<int>change;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int j = 0;j<m;j++){
            cin>>v[i][j];
            pq.push(v[i][j]);
        }
        for(int j = 0;j<m;j++){
            if(pq.top() != v[i][j])change.push_back(j);
            pq.pop();
        }
        if(change.size()>2){
            now = -1;
        }
        if(change.empty())continue;
        else if(ans.first == -1)ans= make_pair(change[0],change[1]);
        else if(change[0] != ans.first||change[1] != ans.second){
            now = -1;
        }
    }
    if(now == -1){
        cout<<"-1\n";
        return;
    }
    if(ans.first == -1){
        cout<<"1 1\n";
        return;
    }
    for(int i = 0;i<n;i++){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int j = 0;j<m;j++){
            pq.push(v[i][j]);
        }
        swap(v[i][ans.first],v[i][ans.second]);
        for(int j = 0;j<m;j++){
            if(pq.top() != v[i][j]){
                cout<<-1<<'\n';
                return;
            }
            pq.pop();
        }
    }
    cout<<ans.first+1<<' '<<ans.second+1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
