#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    int arr[n+1] = {};
    bool used[n+1] = {};
    for(int i = 1;i<=n;i++)cin>>arr[i];
    int cnt = 0;
    while(!used[x]){
        used[x] = true;
        x = arr[x];
        cnt++;
    }
    cout<<cnt;
}