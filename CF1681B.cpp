#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    int m;
    cin>>m;
    long long sum = 0;
    for(int i = 0;i<m;i++){
        int k;
        cin>>k;
        sum += k;
    }
    cout<<v[sum%n]<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
