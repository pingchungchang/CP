#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '.'){
            cout<<s.substr(0,i);
            return 0;
        }
    }
    cout<<s;
    return 0;
}
