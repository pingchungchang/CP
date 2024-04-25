#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    int ans = INT_MAX;
    for(int i = 0;i<=n-m;i++){
        int tmp = v[i+m-1]-v[i];
        tmp += min(abs(v[i]),abs(v[i+m-1]));
        ans = min(ans,tmp);
    }
    cout<<ans;
}
