#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector<int> arr(n,0);
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        arr[i] = k;
    }
    vector<ll> ans(10,0);
    ans[arr[0]]=1;
    for(int i =1;i<n;i++){
        vector<ll> sec(10,0);
        for(int j =0;j<10;j++){
            sec[(arr[i]+j)%10] = (sec[(arr[i]+j)%10]+ans[j])%998244353;
            sec[(arr[i]*j)%10] = (sec[(arr[i]*j)%10]+ans[j])%998244353;
        }
        ans = sec;
    }
    for(int i =0;i<10;i++)cout<<ans[i]<<'\n';
}
