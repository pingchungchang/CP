#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int n;
    cin>>s>>n;
    int pref[s.size()+1] = {};
    s = "#"+s;
    for(int i = 1;i<s.size();i++){
        if(s[i] != 'X')pref[i] = 1;
        pref[i] += pref[i-1];
    }
    int p = 1;
    int ans =0;
    for(int i = 1;i<s.size();i++){
        if(p<i)p = i;
        while(p<s.size()&&pref[p]-pref[i-1]<=n)p++;
        ans = max(ans,p-i);
    }
    cout<<ans;
}