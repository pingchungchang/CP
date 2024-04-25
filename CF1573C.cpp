#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    vector<int> deg(n,0);
    bitset<200005> goneto = {};
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        for(int j = 0;j<k;j++){
            int x;
            cin>>x;
            x--;
            v[x].push_back(i);
            deg[i]++;
        }
    }
    vector<int> dep(n,1);
    queue<int> q;
    for(int i = 0;i<n;i++){
        if(deg[i] == 0){
            goneto[i] = true;
            q.push(i);
        }
    }
    //for(int i = 0;i<n;i++)cout<<deg[i]<<' ';cout<<'\n';
    while(!q.empty()){
        int now = q.front();q.pop();
        for(auto nxt:v[now]){
            deg[nxt]--;
            if(nxt<now){
                dep[nxt] = max(dep[nxt],dep[now]+1);
            }
            else{
                dep[nxt] = max(dep[nxt],dep[now]);
            }
            if(deg[nxt] == 0){
                goneto[nxt] = true;
                q.push(nxt);
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(goneto[i] == false){
            cout<<"-1\n";
            return;
        }
    }
    int ans =0;
    for(int i = 0;i<n;i++)ans = max(ans,dep[i]);
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
