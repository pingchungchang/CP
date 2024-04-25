#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    set<char> st;
    for(int i = 0;i<12;i++){
        cin>>s;
        for(auto &j:s)st.insert(j);
    }
    if(st.find('.') != st.end())st.erase('.');
    if(st.find('X') != st.end())st.erase('X');
    cout<<st.size()<<'\n';
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}