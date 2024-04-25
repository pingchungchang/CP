#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    vector<pair<char,int>> v;
    for(auto &i:a){
        if(v.empty()||v.back().first != i)v.push_back({i,1});
        else v.back().second++;
    }
    int p = 0;
    for(auto &i:v){
        int cnt = 0;
        while(p<b.size()&&b[p] == i.first){
            p++;
            cnt++;
        }
        if(i.second == 1&&cnt != 1){
            cout<<"No";
            return 0;
        }
        else if(cnt < i.second){
            cout<<"No";
            return 0;
        }
    }
    if(p != b.size())cout<<"No";
    else cout<<"Yes\n";
    return 0;
}