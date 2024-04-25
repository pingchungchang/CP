#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("popcnt")
const int mxn = 2505;
bitset<mxn> arr[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int m;
        cin>>m;
        while(m--){
            int k;
            cin>>k;
            arr[i][k] = 1;
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if((arr[i]&arr[j]).count()>0)ans++;
        }
    }
    cout<<ans;
}