#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

struct node{
    int par;
    vector<int>childs;
    ll val;
    bool goneto;
    pair<int,int> change;
    node(){
        change = make_pair(0,0);
        par = -1;
        goneto = 0;
    }
};
ll ans = 0;
pair<ll,ll> cnt;
vector<node>v;
void getroot(int now){
    for(auto nxt:v[now].childs){
        if(nxt == v[now].par)continue;
        v[nxt].par = now;
        getroot(nxt);
    }
    return;
}
void dfs(int now){
    if(v[now].goneto)return;
    cnt.fs += v[now].change.fs;
    cnt.sc += v[now].change.sc;
    v[now].goneto  = 1;
    for(auto nxt:v[now].childs){
        if(nxt == v[now].par)continue;
        dfs(nxt);
    }
    return;
}
int main(){
    int n;
    ll s1 = 0,s2 = 0;
    cin>>n;
    v = vector<node>(n);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>v[i].val>>a>>b;
        s1 += a;s2 += b;
        if(a != b){
            v[i].change = (b == 0?make_pair(1,0):make_pair(0,1));
        }
        pq.push(make_pair(v[i].val,i));
    }
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].childs.push_back(b);
        v[b].childs.push_back(a);
    }
    getroot(0);
    if(s1 != s2){
        cout<<-1<<'\n';
        return 0;
    }
    while(!pq.empty()){
        if(v[pq.top().sc].goneto == 1)pq.pop();
        else{
            cnt = make_pair(0,0);
            dfs(pq.top().sc);
            ans += min(cnt.first,cnt.second)*pq.top().fs*2;
            v[pq.top().sc].change = make_pair(cnt.first-min(cnt.first,cnt.second),cnt.second-min(cnt.first,cnt.second));
            v[pq.top().sc].goneto = 0;
            pq.pop();
        }
    }
    cout<<ans;
}
