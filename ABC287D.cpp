#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>



string s,t;
const int mxn = 3e5+10;
int pref[mxn],suf[mxn];


int main(){
    cin>>s>>t;
    pref[0] = true;
    for(int i = 0;i<t.size();i++){
        if(s[i] == t[i]||t[i] == '?'||s[i] == '?'){
            pref[i+1] = pref[i];
        }
        else pref[i+1] = 0;
    }
    suf[0] = true;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(int i = 0;i<t.size();i++){
        if(s[i] == t[i]||s[i] == '?'||t[i] == '?')suf[i+1] = suf[i];
        else suf[i+1] = 0;
    }
    for(int i = 0;i<=t.size();i++){
        if(pref[i]&&suf[t.size()-i])cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}