#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    for(int i =0;i<s.size();i++){
        printf("%c",s[i]-'J'+'C');
    }
}