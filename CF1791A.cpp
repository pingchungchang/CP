#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "codeforces";
    int t;
    cin>>t;
    while(t--){
        char c;
        cin>>c;
        bool flag = false;
        for(auto &i:s){
            if(i == c){
                cout<<"YES\n";
                flag = true;
                break;
            }
        }
        if(!flag)cout<<"NO\n";
    }
}