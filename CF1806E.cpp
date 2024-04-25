#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3")
#define ll long long

const int mod = 1e9+7;
const int mxn = 1e5+10;
struct chash{
    int operator()(int x)const{return x^mod;}
};

gp_hash_table<int,ll,chash> mp[mxn];
vector<int> childs[mxn];
int par[mxn];
int dep[mxn];
ll arr[mxn];
int sq = sqrt(1e5+10);

ll calc(int a,int b){
    if(a>b)swap(a,b);
    if(a==1)return mp[a][b] = arr[a]*arr[b];
    if(mp[a].find(b) != mp[a].end())return mp[a][b];
    else if(!(dep[a]&((1<<7)-1)))return mp[a][b] = calc(par[a],par[b])+arr[a]*arr[b];
    else return calc(par[a],par[b])+arr[a]*arr[b];
}

void dfs(int now){
    for(auto nxt:childs[now]){
        dep[nxt] = dep[now]+1;
        dfs(nxt);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 2;i<=n;i++)cin>>par[i],childs[par[i]].push_back(i);
    dfs(1);
    tuple<int,int,int> req[q];
    ll ans[q];
    for(int i = 0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<calc(a,b)<<'\n';
        // get<0>(req[i]) = i;
        // cin>>get<1>(req[i])>>get<2>(req[i]);
    }
    /*
    sort(req,req+q,[](tuple<int,int,int> &a,tuple<int,int,int> &b){return dep[get<1>(a)]>dep[get<1>(b)];});
    for(auto &i:req){
        ans[get<0>(i)] = calc(get<1>(i),get<2>(i));
    }
    for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';return 0;
    */
}