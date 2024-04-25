#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string s[n],t[m];
    set<string> st;
    for(auto &i:s)cin>>i;
    for(auto &i:t){
        cin>>i;
        st.insert(i);
    }
    int ans =0;
    for(auto &i:s){
        if(st.find(i.substr(3,3)) != st.end())ans++;
    }
    cout<<ans;
    
}