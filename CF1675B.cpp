#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    int ans = 0;
    for(int i = n-2;i>=0;i--){
        while(arr[i] != 0&&arr[i]>=arr[i+1]){
            ans++;
            arr[i]/=2;
        }
        if(arr[i]>=arr[i+1]){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
