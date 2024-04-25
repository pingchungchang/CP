#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;i+j<=n;j++){
            int k = n-i-j;
            ans = max(ans,2022+abs(j-k)+i*j+j*k+k*k-abs(i*i-j*j));
        }
    }
    cout<<ans;
}
