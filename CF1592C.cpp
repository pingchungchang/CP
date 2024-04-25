#include <bits/stdc++.h>
using namespace std;


struct node{
    vector<int>childs;
    int val;
    int par;
    node(){
        val = 0;
        par = -1;
    }
};
vector<int> intime;
vector<node> v;
void findpar(int now){
    for(auto i:v[now].childs){
        if(i == v[now].par)continue;
        v[i].par = now;
        findpar(i);
    }
    return;
}

void dfs(int now){
    if(v[now].childs.size() == 1&&now != 0)return;
    for(auto nxt:v[now].childs){
        if(nxt == v[now].par)continue;
        dfs(nxt);
        v[now].val ^= v[nxt].val;
    }
    return;
}
void memdfs(int now){
    intime.push_back(now);
    for(auto nxt:v[now].childs){
        if(nxt == v[now].par)continue;
        memdfs(nxt);
    }
    return;
}
void solve(){
    int n,k;
    cin>>n>>k;
    intime = {};
    v = vector<node>(n,node());
    for(int i = 0;i<n;i++){
        cin>>v[i].val;
    }
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].childs.push_back(b);
        v[b].childs.push_back(a);
    }
    findpar(0);
    dfs(0);

    if(v[0].val == 0){
        cout<<"YES\n";
        return;
    }
    else if(k == 2){
        cout<<"NO\n";
        return;
    }
    memdfs(0);
    int v0 = v[0].val;
    bool flag1 = false;
    bool flag2 = false;
    for(int i = intime.size()-1;i>=0;i--){
        int now = intime[i];
        if(flag1&&v[now].val == v0){
            cout<<"YES\n";
            return;
        }
        else if(flag1 == false&&v[now].val == v[0].val){
            while(now != -1){
                v[now].val ^= v0;
                now = v[now].par;
            }
            flag1 = true;
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}


/*
1
5 3
1 1 1 1 3
1 2
2 3
3 4
4 5
*/
