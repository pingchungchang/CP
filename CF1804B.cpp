#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,d,w;
    cin>>n>>k>>d>>w;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans = 0;
    int cnt = 0,lst = 0;
    for(auto &i:arr){
        if(!cnt){
            lst = i+w+d;
            cnt = k;
            ans++;
        }
        else if(i>lst){
            ans++;
            cnt = k;
            lst = i+w+d;
        }
        cnt--;
    }
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}