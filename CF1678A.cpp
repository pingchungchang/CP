#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    set<int> st;
    bool f1 = false,f2 = false;
    int all = 0;
    for(int i = 0;i<n;i++){
        if(v[i] == 0)f1 = true;
        else if(st.find(v[i]) != st.end())f2 = true;
        st.insert(v[i]);
        if(v[i] != 0)all++;
    }
    if(f1){
        cout<<all<<'\n';
        return;
    }
    else if(f2){
        cout<<all<<'\n';
        return;
    }
    else{
        cout<<all+1<<'\n';
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
