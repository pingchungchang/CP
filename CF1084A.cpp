#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    int ans = INT_MAX;
    for(int i = 0;i<n;i++){
        int tmp = 0;
        for(int j= 0;j<n;j++){
            tmp += v[j]*4*max(i,j);
        }
        ans = min(ans,tmp);
    }
    cout<<ans;
}
