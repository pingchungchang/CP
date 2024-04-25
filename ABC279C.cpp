#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> a(m,string(n,'a')),b(m,string(n,'a'));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)cin>>a[j][i];
    }
    for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)cin>>b[j][i];
    multiset<string> st;
    for(auto &i:a)st.insert(i);
    for(auto &i:b){
        if(st.find(i) == st.end()){
            cout<<"No";
            return 0;
        }
        st.erase(st.find(i));
    }
    cout<<"Yes";
}