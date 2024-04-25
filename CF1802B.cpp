#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int kn = 0,un = 0;
    int ans = 0;
    for(auto &i:arr){
        if(i == 1)un++;
        else{
            kn+= un;
            un = 0;
        }
        ans = max(ans,un+(kn!=0?kn/2+1:0));
    }
    cout<<ans;
    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}