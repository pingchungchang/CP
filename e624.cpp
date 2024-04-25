#include <bits/stdc++.h>
using namespace std;

string a,b;

void solve(){
    int p1 = 0,p2 = 0,n = a.size(),m = b.size();
    while(p1 != n&&p2 != m){
        if(a[p1] == b[p2]){
            p1++;
        }
        p2++;
    }
    if(p1 == n)cout<<"Yes\n";
    else cout<<"No\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>a>>b){
        if(a == "-1")return 0;
        solve();
    }
}
