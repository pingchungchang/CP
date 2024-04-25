#include <bits/stdc++.h>
using namespace std;

void solve(){
    int odd = 0,even = 0;
    int n,x;
    cin>>n>>x;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(k%2 == 1)odd++;
        else even++;
    }
    x -= even;
    if(x<0)x = 1;
    if(x%2 == 0&&even == 0){
        cout<<"No\n";
        return;
    }
    else if(x%2 == 0)x++;
    if(odd>=x)cout<<"Yes\n";
    else cout<<"No\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
