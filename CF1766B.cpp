#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    set<string> st;
    string pre;
    for(int i = 0;i<n-1;i++){
        if(st.find(s.substr(i,2)) != st.end()){
            cout<<"YES\n";
            return;
        }
        st.insert(pre);
        pre = s.substr(i,2);
    }
    cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}