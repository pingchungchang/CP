#include <bits/stdc++.h>
using namespace std;

const int mxn = 4e5+10;
vector<int> paths[mxn];
bitset<mxn> vis;


bool check(int now){
    // cout<<now<<"<"<<endl;
    vis[now] = true;
    bool re = true;
    if(paths[now].size() != 2)re = false;
    for(auto nxt:paths[now]){
        // cout<<nxt<<endl;
        if(!vis[nxt])re = check(nxt)&&re;
    }
    return re;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        paths[i*2].push_back(i*2-1);
        paths[i*2-1].push_back(i*2);
    }
    for(int i = 0;i<m;i++){
        int a,b;
        char c,d;
        cin>>a>>c>>b>>d;
        int da = 0,db = 0;
        if(c == 'B')da = 1;
        if(d == 'B')db = 1;
        paths[a*2-da].push_back(b*2-db);
        paths[b*2-db].push_back(a*2-da);
    }
    int cnt = 0,c2 = 0;
    for(int i = 1;i<=n*2;i++){
        if(!vis[i]){
            // cout<<i<<endl;
            if(check(i))cnt++;
            else c2++;
        }
    }
    cout<<cnt<<' '<<c2;
}