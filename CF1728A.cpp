#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    int total = 0;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        total += arr[i];
    }
    if(*max_element(arr+1,arr+n+1)>total-*max_element(arr+1,arr+n+1))cout<<max_element(arr+1,arr+n+1)-arr<<'\n';
    else cout<<"1\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}