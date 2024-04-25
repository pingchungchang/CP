#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i+= 2){
        if(s[i] == 'L'){
            cout<<"No";
            return 0;
        }
    }
    for(int i = 1;i<s.size();i+= 2){
        if(s[i] == 'R'){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
