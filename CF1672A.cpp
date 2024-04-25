#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int total =0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        total += k-1;
    }
    if((total)&1)cout<<"errorgorn\n";
    else cout<<"maomao90\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();

}


