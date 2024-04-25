#include <bits/stdc++.h>
using namespace std;

void solve(){
    int cnt = 0;
    int total =0;
    int s;
    cin>>s;
    while(total<s){
        cnt++;
        total += cnt*2-1;
    }
    cout<<cnt<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}