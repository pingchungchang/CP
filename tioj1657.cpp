#include <bits/stdc++.h>
using namespace std;

int n,m;
bool fflag = false;
void solve(){
    if(fflag)cout<<'\n';
    fflag = true;
    for(int i = 1;i<=n;i++){
        if(i != 1)cout<<'\n';
        for(int j = 1;j<=m;j++){
            if(j != 1)cout<<' ';
            cout<<i<<"*"<<j<<"="<<i*j;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m)solve();
}