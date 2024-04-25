#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    bool ans = false;
    for(int i = 0;i<(int)s.size()-(int)t.size()+1;i++){
        if(s.substr(i,t.size()) == t)ans = true;
    }
    if(ans)cout<<"Yes";
    else cout<<"No";
}