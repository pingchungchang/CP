#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    vector<int>vv = v;
    sort(vv.begin(),vv.end());
    for(int i = n-2;i>=0;i-=2){
        if(v[i]>v[i+1])swap(v[i],v[i+1]);
    }
    for(int i = 0;i<n;i++){
        if(v[i] != vv[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
