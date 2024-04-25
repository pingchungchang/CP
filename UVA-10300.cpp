#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        long long ans = 0;
        for(int j=0;j<a;j++){
            long long x,y,z;
            cin>>x>>y>>z;
            ans += x*z;
        }
        cout<<ans<<endl;
    }
}
