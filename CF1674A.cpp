#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a,b;
    cin>>a>>b;
    if(b%a != 0){
        cout<<"0 0\n";
        return;
    }
    cout<<1<<' '<<b/a<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
