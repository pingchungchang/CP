#include <bits/stdc++.h>
using namespace std;

struct node{
    int id;
    int pos;
    int dir;
    node(){}
};
int tt;
bool cmp(node a,node b){
    return a.pos<b.pos;
}
class Compare{
public:
    bool operator()(node a,node b){
        if(a.pos != b.pos)return a.pos>b.pos;
        else return a.id>b.id;
    }
};
void solve(){
    tt++;
    int n,l;
    cin>>n>>l;
    vector<node> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i].pos>>v[i].dir;
        v[i].id = i+1;
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> lef,rig;
    for(int i = 0;i<n;i++){
        if(v[i].dir == 0)lef.push_back(v[i].pos);
        else rig.push_back(l-v[i].pos);
    }
    priority_queue<node,vector<node>,Compare> pq;
    for(int i = 0;i<lef.size();i++){
        node tmp;
        tmp.id = v[i].id;tmp.pos = lef[i];
        pq.push(tmp);
    }
    for(int i = lef.size();i<n;i++){
        node tmp;
        tmp.id = v[i].id,tmp.pos = rig[i-lef.size()];
        pq.push(tmp);
    }
    cout<<"Case #"<<tt<<": ";
    while(!pq.empty()){
        cout<<pq.top().id<<' ';
        pq.pop();
    }
    cout<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        solve();
    }
}
