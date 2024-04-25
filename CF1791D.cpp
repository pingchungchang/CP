#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> a,b;
    for(auto &i:s){
        a[i]++;
    }
    int ans = a.size(); 
    for(auto &i:s){
        a[i]--;
        if(a[i] == 0)a.erase(i);
        if(a.empty())break;
        b[i]++;
        ans = max((int)a.size()+(int)b.size(),ans);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}