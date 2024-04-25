#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    vector<int>paths;
    node(){}
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<node> v(n,node());
    for(int i = 0;i<n;i++)cin>>v[i].val;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;a--,b--;
        v[a].paths.push_back(b);
        v[b].paths.push_back(a);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        bool b = true;
        for(auto nxt:v[i].paths){
            if(v[nxt].val>=v[i].val)b = false;
        }
        if(b)ans++;
    }
    cout<<ans;
}
