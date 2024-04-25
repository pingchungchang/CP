#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int n = a.size();
    map<char,char> mp;
    for(int i = 0;i<n;i++){
        if(mp.find(a[i]) != mp.end()&&mp[a[i]] != b[i]){
            cout<<"No";
            return 0;
        }
        else{
            mp[a[i]] = b[i];
            
        }
    }
    int cnt = 0;
    for(auto &i:mp){
        if(i.first != i.second)cnt++;
    }
    if(cnt&1)cout<<"No";
    else cout<<"Yes";
}