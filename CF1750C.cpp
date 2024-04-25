#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector<int> v;
    bool same = false,dif = false;
    for(int i = 0;i<n;i++){
        if(a[i] == b[i])same = true;
        else dif = true;
    }
    if(same&&dif){
        cout<<"NO\n";
        return;
    }
    for(int i = 0;i<n;i++){
        if(a[i] == '1')v.push_back(i);
    }
    vector<pii> ans;
    int head = b[0]-'0';
    if(v.empty())v = {1,1};
    if((head+v.size()-(v[0] == 0))&1){
        ans.push_back({1,1});
        ans.push_back({2,n});
        ans.push_back({1,n});
    }
    cout<<"YES\n";
    cout<<ans.size()+v.size()<<'\n';
    for(auto &i:v)cout<<i+1<<' '<<i+1<<'\n';
    for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}