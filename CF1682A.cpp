#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    int l = s.size()/2;
    int r = s.size()/2;
    int mid = s.size()/2;
    for(int i = mid;i>=0;i--){
        if(s[i] == s[mid])l = i;
        else break;
    }
    for(int i = mid;i<n;i++){
        if(s[i] == s[mid])r = i;
        else break;
    }
    cout<<r-l+1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
