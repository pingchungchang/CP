#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long ans = 0;
    long long p = 1;
    for(int i = s.size()-1;i>=0;i--){
        ans += p*(s[i]-'A'+1);
        p *= 26;
    }
    cout<<ans;
}