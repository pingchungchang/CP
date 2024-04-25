#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> mp;
    set<int>st;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        mp[k].push_back(i+1);
    }
    for(int i = 0;i<m;i++){
        int k;
        cin>>k;
        st.insert(k);
    }
    for(auto i:mp.rbegin()->second){
        if(st.find(i) != st.end()){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}
