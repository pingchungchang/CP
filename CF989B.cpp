#include <bits/stdc++.h>
using namespace std;

string s;
int n,m;
int main(){
    cin>>n>>m;
    cin>>s;
    bool ans = false;
    for(int i = 0;i<n-m;i++){
        if(s[i] == s[i+m]&&s[i] != '.')continue;
        ans = true;
        if(s[i] == '.'){
            if(s[i+m] != '.'){
                s[i] = ('1'-s[i+m])+'0';
            }
            else{
                s[i] = '1';
                s[i+m] = '0';
            }
        }
        else{
            s[i+m] = ('1'-s[i])+'0';
        }
    }
    for(auto &i:s)if(i == '.')i = '1';
    if(ans)cout<<s;
    else cout<<"NO";
}
