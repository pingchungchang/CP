#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a,b;
    cin>>a>>b;
    if(a.size()>b.size()){
        cout<<0<<'\n';
    }
    else if(a.size() == b.size()&&a>b){
        cout<<0<<'\n';
    }
    else{
        cout<<1<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
