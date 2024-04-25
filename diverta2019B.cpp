#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int ans = 0;
    for(int i = 0;i<=n/r;i++){
        for(int j = 0;j<=(n-r*i)/g;j++){
            int lef = n-r*i-g*j;
            if(lef%b == 0)ans++;
        }
    }
    cout<<ans;
}
