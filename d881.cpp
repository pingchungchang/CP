#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    while(cin>>n){
        ll ans = 0;
        ans += 50*(50+1)/2;
        for(int i =1;i<=50;i++){
            ans += (i-1)*(i-2)/2*n;
        }
        cout<<ans<<'\n';
    }
}