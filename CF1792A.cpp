#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int one = 0;
    int nn = n;
    while(nn--){
        int k;
        cin>>k;
        if(k == 1)one++;
    }
    cout<<(one+1)/2+(n-one)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}