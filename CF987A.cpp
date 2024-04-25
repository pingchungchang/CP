#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<string,string> mp;
    mp["purple"] = "Power";
    mp["red"] = "Reality";
    mp["orange"] = "Soul";
    mp["yellow"] = "Mind";
    mp["blue"] = "Space";
    mp["green"] = "Time";
    set<string> st;
    for(auto &i:mp)st.insert(i.second);
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        st.erase(mp[s]);
    }
    cout<<st.size()<<'\n';
    for(auto &i:st)cout<<i<<'\n';
    return;

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
}