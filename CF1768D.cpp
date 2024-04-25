#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 1;i<=n;i++)cin>>arr[i];
    int goneto[n+1] = {};
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(goneto[i])continue;
        cnt++;
        int now = i;
        while(!goneto[now]){
            goneto[now] = cnt;
            now = arr[now];
        }
    }
    for(int i = 1;i<n;i++){
        if(goneto[i] == goneto[i+1]){
            cout<<n-cnt-1<<'\n';
            return;
        }
    }
    cout<<n-cnt+1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}