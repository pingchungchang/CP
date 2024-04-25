#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool flag = true;
    if(s[0]<'A'||s[0]>'Z'||s.back()<'A'||s.back()>'Z')flag = false;
    if(s.size() != 8){
        cout<<"No";
        return 0;
    }
    for(int i = 1;i<s.size()-1;i++){
        if(s[1] == '0')flag = false;
        if(s[i]<'0'||s[i]>'9')flag = false;
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
}