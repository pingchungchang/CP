#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    vector<int> appear[26];
    for(int i = 0;i<s.size();i++){
        appear[s[i]-'a'].push_back(i);
    }
    int mr = 0;
    vector<pair<int,int>> del;
    for(int i = 0;i<26;i++){
        if(!appear[i].empty())del.push_back({appear[i].back(),i});
    }
    sort(del.rbegin(),del.rend());
    int cnt = del.size();
    for(auto &i:del){
        auto now = i.second;
        if(appear[now].size()%cnt != 0){
            cout<<"-1\n";
            return;
        }
        mr = max(mr,appear[now][appear[now].size()/cnt-1]);
        cnt--;
    }
    int num[26] = {};
    for(int i = 0;i<=mr;i++)num[s[i]-'a']++;
    cnt = del.size();
    for(auto &i:del){
        auto now = i.second;
        if(num[now] != appear[now].size()/cnt){
            cout<<"-1\n";
            return;
        }
        cnt--;
    }
    reverse(del.begin(),del.end());
    string t;
    set<char> st;
    string ss = s.substr(0,mr+1);
    for(auto &i:del){
        for(auto &j:ss){
            if(st.find(j) != st.end())continue;
            t += j;
        }
        st.insert('a'+i.second);
    }
    // cout<<t<<endl<<endl;
    if(s != t){
        cout<<"-1\n";
        return;
    }
    cout<<s.substr(0,mr+1)<<' ';for(auto &i:del)cout<<(char)(i.second+'a');cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}