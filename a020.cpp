#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans = (s[0]-'A')*9+(s[0]-'A'+10)/10;
    for(int i = 1;i<s.size()-1;i++){
        ans += i*s[s.size()-1-i];
    }
    ans += s[s.size()-1]-'0';
    if(ans%10) cout<<"fake";
    else cout<<"real";
}
