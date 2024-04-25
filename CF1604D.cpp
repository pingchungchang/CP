#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a,b;
    cin>>a>>b;
    if(a == b)cout<<a<<'\n';
    else if(a<b){
        cout<<(a<b-a?(b+a+(b-a)/a*a-a)/2:(a+b)/2)<<'\n';
    }
    else{
        cout<<b+a<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
