#include <bits/stdc++.h>
using namespace std;

const int mxn = 32768;
int getans(int n){
    for(int i = 0;i<=15;i++){
        if(((1<<i)&n) != 0){
            return 15-i;
        }
    }
    return 0;
}
void solve(){
    int n;
    cin>>n;
    int ans = 16;
    for(int i = 0;i<16;i++){
        ans = min(ans,getans(n+i)+i);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
