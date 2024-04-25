#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
void solve(){
    vector<int> v;
    string s;
    int n;
    cin>>n;
    while(n--)s += "BAN";
    n = s.size();
    vector<pii> ans;
    for(int i = n-1;i>=0;i--){
        if(s[i] == 'A')v.push_back(i);
    }
    for(int i = n-1;i>=0;i--){
        if(v.empty()||i<=v.back())break;
        if(s[i] != 'N')continue;
        ans.push_back({i+1,v.back()+1});
        v.pop_back();
    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans){
        cout<<i.fs<<' '<<i.sc<<'\n';
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}