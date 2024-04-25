#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> v(n+1);
    for(int i = 1;i<=n;i++)cin>>v[i];
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        int k = v[i]-i;
        if(mp.count(k) != 0)ans += mp[k];
        if(mp.count(-v[i]-i) == 0)mp[-v[i]-i] = 1;
        else mp[-v[i]-i]++;
    }
    cout<<ans;
}
