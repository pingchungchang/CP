#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

typedef pair<int,int> pii;
#define fs first
#define sc second
const int mxn = 1e5+10;
pii req[mxn];
int ans[mxn];
vector<pii> cols[mxn];
int dsu[mxn],sz[mxn];
vector<int> v;
unordered_map<long long,vector<int>> mp;
int root(int now){
    return now == dsu[now]?now:dsu[now] = root(dsu[now]);
}
void onion(int a,int b){
    int ra = root(a),rb = root(b);
    if(ra == rb)return;
    if(sz[ra]<sz[rb])swap(ra,rb);
    sz[ra] += sz[rb];
    dsu[rb] = ra;
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        cols[c].push_back({a,b});
    }
    for(int i = 1;i<=n;i++){
        dsu[i] = i;
        sz[i] = 1;
    }
    int q;
    cin>>q;
    int sq = sqrt(m);
    for(int i = 1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        req[i] = {a,b};
        mp[100001LL*a+b].push_back(i);
    }
    // for(auto &i:mp)cout<<i.fs<<','<<i.sc<<' ';cout<<'\n';
    for(int i = 1;i<=m;i++){
        for(auto &j:cols[i]){
            onion(j.fs,j.sc);
            v.push_back(j.fs);
            v.push_back(j.sc);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        if(cols[i].size()>sq){
            // cout<<i<<' '<<q<<endl;
            for(int j = 1;j<=q;j++){
                // cout<<req[j].fs<<' '<<root(req[j].fs)<<endl;
                if(root(req[j].fs) == root(req[j].sc))ans[j]++;
            }
        }
        else{
            for(int j = 0;j<v.size();j++)for(int k = j+1;k<v.size();k++)if(root(v[j]) == root(v[k])&&mp.find(100001LL*v[j]+v[k])!=mp.end())for(auto &l:mp[100001LL*v[j]+v[k]])ans[l]++;
            // for(int j= 1;j<=n;j++)cout<<root(j)<<' ';cout<<'\n';
            // for(int j = 0;j<v.size();j++){
            //     for(int k = j+1;k<v.size();k++)cout<<v[j]<<' '<<v[k]<<',';
            // }
            // cout<<'\n';
        }
        while(!v.empty()){
            dsu[v.back()] = v.back();
            sz[v.back()] = 1;
            v.pop_back();
        }
        // for(int j = 1;j<=q;j++)cout<<ans[j]<<' ';cout<<'\n';
    }
    for(int i = 1;i<=q;i++)cout<<ans[i]<<'\n';
    return 0;
}