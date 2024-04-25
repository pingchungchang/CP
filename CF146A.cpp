#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto i:s)if(i != '4'&&i != '7'){
        cout<<"NO\n";
        return 0;
    }
    int s1 = 0,s2 = 0;
    for(int i = 0;i<s.size()/2;i++)s1 += s[i]-'0';
    for(int i = s.size()/2;i<s.size();i++)s2 += s[i]-'0';
    if(s1 == s2)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
