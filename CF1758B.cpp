#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n&1){
        while(n--)cout<<1<<' ';cout<<'\n';
        return;
    }
    //a&b = 0 and a+b = n+1;
    int total = n*2;
    for(int i = 0;i<n-2;i++){
        cout<<2<<' ';
        total--;
    }
    cout<<3<<' '<<1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}