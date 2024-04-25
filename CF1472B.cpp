#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int o = 0,t = 0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(k == 1)o++;
        else t++;
    }
    if((t*2+o)%2 != 0){
        cout<<"NO\n";
        return;
    }
    else if((t*2+o)/2%2 == 0){
        cout<<"YES\n";
    }
    else if(o != 0){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
