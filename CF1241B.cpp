#include <bits/stdc++.h>
using namespace std;


void solve(){
    string a,b;
    cin>>a>>b;
    set<char> st,s2;
    for(auto i:b)st.insert(i);
    for(auto i:a)s2.insert(i);
    for(auto i:st){
        if(s2.find(i) != s2.end()){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
