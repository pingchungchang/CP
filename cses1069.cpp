#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans =0;
    int n = 1;
    for(int i =1;i<s.size();i++){
        if(s[i] == s[i-1])n++;
        else{
            ans = max(ans,n);
            n = 1;
        }
    }
    ans = max(ans,n);
    cout<<ans;
}
