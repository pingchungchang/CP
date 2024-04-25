#include <bits/stdc++.h>
using namespace std;

int main(){
    set<vector<int>> st;
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        vector<int> v(m);
        for(auto &i:v)cin>>i;
        st.insert(v);
    }
    cout<<st.size();
}