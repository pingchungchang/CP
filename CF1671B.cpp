#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    int s = v[0]+1;
    for(auto i:v){
        if(abs(i-s)>1){
            cout<<"NO\n";
            return;
        }
        s++;
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
