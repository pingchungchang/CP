#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 1e5+10;
vector<int> paths[mxn];
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        cout<<paths[i].size()<<' ';
        sort(paths[i].begin(),paths[i].end());
        for(auto &j:paths[i])cout<<j<<' ';cout<<'\n';
    }
    return 0;
}