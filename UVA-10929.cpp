#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        if(s == "0")return 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(i&1)ans+=s[i]-'0';
            else ans -= s[i]-'0';
        }
        if(ans%11 == 0)cout<<s<<" is a multiple of 11.\n";
        else cout<<s<<" is not a multiple of 11.\n";
    }
}