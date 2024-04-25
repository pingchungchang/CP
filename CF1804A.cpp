#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    a = abs(a),b = abs(b);
    if(abs(b-a)<=1){
        cout<<a+b<<'\n';
        return;
    }
    if(a<b)swap(a,b);
    int ans = b*2;
    a -= b;
    ans += a*2-1;
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}