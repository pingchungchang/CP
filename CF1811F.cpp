#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
bool flag;
vector<int> paths[mxn];
bool vis[mxn];
vector<int> st;

void clean(int k){
    int n =k;
    for(int i = 0;i<=n;i++){
        paths[i].clear();
    }
    fill(vis,vis+k+1,false);
    return;
}

int dfs(int now,int head){
    vis[now] = true;
    st.push_back(now);
    int sz = 1;
    for(auto nxt:paths[now]){
        if(paths[now].size() == 2&&paths[nxt].size() == 4&&head != nxt){
            flag = false;
            return 0;
        }
        if(vis[nxt])continue;
        if(paths[nxt].size() == 2)sz += dfs(nxt,head);
        else if(paths[now].size() != 4&&nxt != head){
            flag = false;
            return 0;
        }
    }
    return sz;
}

int dfs2(int now){
    vis[now] = true;
    st.push_back(now);
    // cout<<now<<' ';
    int sz = 1;
    for(auto nxt:paths[now]){
        if(vis[nxt])continue;
        // cout<<nxt<<":"<<paths[nxt].size()<<' '<<vis[nxt]<<',';
        if(paths[nxt].size() == 4)sz += dfs2(nxt);
    }
    return sz;
}

void solve(){
    int n,m;
    cin>>n>>m;
    flag = true;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(paths[i].size() == 4)cnt++;
    }
    if(1LL*cnt*(cnt+1) != m||1LL*cnt*cnt != n){
        cout<<"NO\n";
        clean(n);
        return;
    }
    int two = 0;
    for(int i = 1;i<=n;i++){
        // cout<<i<<":";for(auto &j:paths[i])cout<<j<<',';cout<<endl;
        if(paths[i].size() != 2&&paths[i].size() != 4){
            cout<<"NO\n";
            clean(n);
            return;
        }
    }
    fill(vis,vis+n+1,false);
    for(int i = 1;i<=n;i++){
        if(paths[i].size() == 4){
            if(dfs(i,i) != cnt){
                cout<<"NO\n";
                clean(n);
                return;
            }
            while(!st.empty()){
                vis[st.back()] = false;
                st.pop_back();
            }
        }
    }
    fill(vis,vis+n+1,false);
    for(int i = 1;i<=n;i++){
        if(!vis[i]&&paths[i].size() == 4){
            if(dfs2(i) != cnt){
                cout<<"NO\n";
                clean(n);
                return;
            }
            while(!st.empty()){
                vis[st.back()] = false;
                st.pop_back();
            }
        }
    }
    if(!flag){
        cout<<"NO\n";
    }
    else cout<<"YES\n";
    clean(n);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}