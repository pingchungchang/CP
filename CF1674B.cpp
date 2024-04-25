#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,int>mp;
    int idx = 1;
    for(char a = 'a';a <='z';a++){
        for(char b = 'a';b<='z';b++){
            if(a == b)continue;
            string s = string(1,a)+b;
            mp[s] = idx;
            idx++;
        }
    }
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        string s;
        cin>>s;
        cout<<mp[s]<<'\n';
    }
}
