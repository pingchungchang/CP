#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;
    if(a[0] == b[0]){
        cout<<"YES\n";
        cout<<a[0]<<"*\n";
        return;
    }
    if(a.back() == b.back()){
        cout<<"YES\n";
        cout<<"*"<<b.back()<<'\n';
        return;
    }
    for(int i = 1;i<a.size();i++){
        for(int j = 1;j<b.size();j++){
            if(a[i-1] == b[j-1]&&a[i] == b[j]){
                cout<<"YES\n";
                cout<<"*"<<a[i-1]<<a[i]<<"*\n";
                return;
            }
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}