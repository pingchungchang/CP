#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    if(s.size() == 1){
        cout<<s<<'\n';
    }
    else if(s.size() == 2){
        cout<<s[1]<<'\n';
    }
    else cout<<*min_element(s.begin(),s.end())<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
