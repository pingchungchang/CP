#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

void solve(){
    pii s,e;
    int n,m;
    cin>>n>>m;
    map<pii,int> mp[n+1][m+1];
    cin>>s.fs>>s.sc>>e.fs>>e.sc;
    pii dir;
    string ss;
    cin>>ss;
    if(ss[0] == 'D')dir.fs = 1;
    else dir.fs = -1;
    if(ss[1] == 'L')dir.sc = -1;
    else dir.sc = 1;
    int cnt = 0;
    while(mp[s.fs][s.sc].find(dir) == mp[s.fs][s.sc].end()){
        // cout<<s.fs<<' '<<s.sc<<' '<<dir.fs<<' '<<dir.sc<<endl;
        mp[s.fs][s.sc][dir] = cnt;
        int flag = true;
        if(s.fs+dir.fs==0)dir.fs = -dir.fs,cnt+=flag,flag = 0;
        else if(s.fs+dir.fs == n+1)dir.fs = -dir.fs,cnt+=flag,flag = 0;;
        if(s.sc+dir.sc == 0)dir.sc = -dir.sc,cnt+=flag,flag =0;
        else if(s.sc+dir.sc == m+1)dir.sc = -dir.sc,cnt+=flag,flag = 0;
        s.fs += dir.fs;
        s.sc += dir.sc;
    }
    if(mp[e.fs][e.sc].size() == 0)cout<<"-1\n";
    else{
        int ans = n*m;
        for(auto &i:mp[e.fs][e.sc])ans = min(ans,i.sc);
        cout<<ans<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}