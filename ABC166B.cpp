#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1,0);
    for(int i = 0;i<k;i++){
        int t;
        cin>>t;
        for(int j = 0;j<t;j++){
            int m;
            cin>>m;
            v[m] = 1;
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(v[i] == 0)ans++;
    }
    cout<<ans;
}
