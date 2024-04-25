#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<string> st;
    vector<pair<string,int>> v;
    for(int i = 0;i<n;i++){
        string s;
        int k;
        cin>>s>>k;
        if(st.find(s) != st.end()){
            v.push_back(make_pair(s,-1));
        }
        else v.push_back(make_pair(s,k));
        st.insert(s);
    }
    pair<int,int> ans = make_pair(INT_MAX,-1);
    for(int i = 0;i<n;i++){
        if(ans.second<v[i].second)ans = make_pair(i+1,v[i].second);
    }
    cout<<ans.first;
}
