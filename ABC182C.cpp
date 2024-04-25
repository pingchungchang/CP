#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int ans = 1e9;
    for(int i = 0;i<(1<<s.size());i++){
        int total = 0;
        for(int j = 0;j<s.size();j++){
            if((1<<j)&i)total += s[j]-'0';
        }
        if(total %3 == 0){
            ans = min(ans,(int)s.size()-__builtin_popcount(i));
        }
    }
    if(ans >= s.size())cout<<"-1";
    else cout<<ans;
    return 0;
}