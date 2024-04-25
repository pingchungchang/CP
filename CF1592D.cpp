#include <bits/stdc++.h>
using namespace std;

const int mxn = 1010;
vector<int> tree[mxn];
int par[mxn];
int n,tar;
vector<int> eul;
int ask(int s,int e){
    vector<int> v;
    for(int i = s;i<=e;i++)v.push_back(eul[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<"? "<<v.size()<<' ';for(auto &i:v)cout<<i<<' ';cout<<endl;
    int re;
    cin>>re;
    return re;
}
void dfs(int now,int fa){
    par[now] = fa;
    eul.push_back(now);
    for(auto nxt:tree[now]){
        if(nxt == fa)continue;
        dfs(nxt,now);
        eul.push_back(now);
    }
}
int main(){
    cin>>n;
    vector<int> v;
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,1);
    // for(auto &i:eul)cout<<i<<' ';cout<<endl;
    int l = 0,r = eul.size()-1;
    tar = ask(0,eul.size()-1);
    while(r-l != 1){
        int mid = (l+r+1)>>1;
        if(ask(l,mid) == tar)r = mid;
        else l = mid;
        // cout<<l<<' '<<mid<<' '<<r<<endl;
    }
    cout<<"! "<<eul[l]<<' '<<eul[r]<<endl;
}