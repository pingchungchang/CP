#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    set<int> s1,s2;
    while(n--){
        int k;
        cin>>k;
        s1.insert(k);
    }
    while(m--){
        int k;
        cin>>k;
        s2.insert(k);
    }
    set<int> ans;
    for(auto &i:s1){
        if(s2.find(i) == s2.end())ans.insert(i);
    }
    for(auto &i:s2)if(s1.find(i) == s1.end())ans.insert(i);
    for(auto &i:ans)cout<<i<<' ';return 0;
}