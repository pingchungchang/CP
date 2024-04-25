#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int big = 0;
    unordered_map<int,int> mp;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        big = max(big,k);
        if(mp.count(k) == 0)mp[k] = 1;
        else mp[k]++;
    }
    int ans = 1;
    for(int i = 2;i<=big;i++){
        int cnt = 0;
        for(int j = i;j<=big;j+=i){
            if(mp.count(j) != 0)cnt += mp[j];
            if(cnt>=2){
                ans = i;
                break;
            }
        }
    }
    cout<<ans;

}
