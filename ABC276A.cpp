#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans = -2;
    for(int i = 0;i<s.size();i++)if(s[i] == 'a')ans = max(ans,i);
    cout<<ans+1<<'\n';
}