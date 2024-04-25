#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    if(n==1&&m<=2){
        cout<<m-1<<'\n';
    }
    else if(n == 1){
        cout<<"-1\n";
    }
    else{
        int d = (m-n);
        if(d&1)cout<<(n-1)*2+d*2-1;
        else cout<<(n-1)*2+d*2;
        cout<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}