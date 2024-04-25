#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s += 'W';
    vector<string> v;
    string tmp;
    for(auto i:s){
        if(i == 'W'){
            if(tmp.size() != 0)v.push_back(tmp);
            tmp = "";
        }
        else{
            tmp += i;
        }
    }
    for(auto now:v){
        bool done = false;
        for(int i = 1;i<now.size();i++){
            if(now[i] != now[i-1])done = true;
        }
        if(now.size()<2)done = false;
        if(done == false){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
