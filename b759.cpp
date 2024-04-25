#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++){
        for(int j = i;j<s.size()+i;j++){
            cout<<s[j%s.size()];
        }
        cout<<endl;
    }

}