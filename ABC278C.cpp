#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<int,set<int>> mp;
    int n,q;
    cin>>n>>q;
    while(q--){
        int t,a,b;
        cin>>t>>a>>b;
        if(t == 1){
            mp[a].insert(b);
        }
        else if(t == 2)mp[a].erase(b);
        else{
            if(mp[a].find(b) != mp[a].end()&&mp[b].find(a) != mp[b].end())cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}