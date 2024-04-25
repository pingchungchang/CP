#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    int m;
    cin>>m;
    vector<int>b(m);
    for(int i = 0;i<m;i++)cin>>b[i];
    if(*max_element(a.begin(),a.end())>=*max_element(b.begin(),b.end())){
        cout<<"Alice\n";
    }
    else cout<<"Bob\n";
    if(*max_element(b.begin(),b.end())>=*max_element(a.begin(),a.end())){
        cout<<"Bob\n";
    }
    else cout<<"Alice\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
