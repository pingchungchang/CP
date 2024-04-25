#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>t;
    for(int i = 0;i<s.size();i++){
        if(s[i] != t[i]){
            cout<<i+1;
            return 0;
        }
    }
    cout<<s.size()+1;
}