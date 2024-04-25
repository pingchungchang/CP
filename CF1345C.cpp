#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)cin>>i;
    for(auto &i:v){
        i%= n;
    }
    set<int> st;
    for(int i = 0;i<n;i++){
        st.insert((i+v[i]+n)%n);
    }
    if(st.size() != n){
        cout<<"NO\n";
        return;
    }
    else cout<<"YES\n";
    return;
/*
*/
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}