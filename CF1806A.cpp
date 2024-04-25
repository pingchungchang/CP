#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d<b){
        cout<<-1<<'\n';
        return;
    }
    int delta = d-b;
    a += delta;
    if(a<c){
        cout<<"-1\n";
        return;
    }
    int ans = delta+(a-c);
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
/*
*/