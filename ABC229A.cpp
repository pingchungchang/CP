#include <bits/stdc++.h>
using namespace std;

int main(){
    string s[2];
    cin>>s[0]>>s[1];
    string t = s[0]+s[1];
    int cnt = 0;
    for(auto &i:t)cnt += (i == '.');
    if(cnt == 1||cnt>2){
        cout<<"Yes";
        return 0;
    }
    else{
        if(t == "#..#"||t == ".##.")cout<<"No";
        else cout<<"Yes";
    }
    return 0;
}