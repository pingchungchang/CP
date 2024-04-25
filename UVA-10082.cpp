#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<string> v(4);
    v[0] = "`1234567890-=";
    v[1] = "QWERTYUIOP[]\\";
    v[2] = "ASDFGHJKL;'";
    v[3] = "ZXCVBNM,./";
    unordered_map<char,char> m;
    for(int i = 0;i<v.size();i++){
        for(int j =1;j<v[i].size();j++){
            m[v[i][j]] = v[i][j-1];
        }
    }
    while(getline(cin,s)){
        int n = s.size();
        for(int i =0;i<n;i++){
            if(m.count(s[i]) == 0)printf("%c",s[i]);
            else printf("%c",m[s[i]]);
        }
        printf("\n");
    }
}