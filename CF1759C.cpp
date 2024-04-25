#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l,r,x,a,b;
    cin>>l>>r>>x>>a>>b;
    if(a == b){
        cout<<"0\n";
        return;
    }
    if(abs(a-b)>=x){
        cout<<"1\n";
        return;
    }
    if(abs(a-l)>=x&&abs(b-l)>=x)cout<<"2\n";
    else if(abs(a-r)>=x&&abs(b-r)>=x)cout<<"2\n";
    else if(abs(a-l)>=x&&abs(r-l)>=x&&abs(b-r)>=x)cout<<"3\n";
    else if(abs(a-r)>=x&&abs(r-l)>=x&&abs(b-l)>=x)cout<<"3\n";
    else cout<<"-1\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}