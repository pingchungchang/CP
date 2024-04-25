#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool flag = false;
    for(auto &i:s){
        if(i == '\"')flag ^=1;
        else if(i == ','){
            if(!flag)i = '.';
        }
    }
    cout<<s;
    return 0;
}