#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int total = 0;
    for(auto &i:arr)total += i;
    for(int i = 1;i<n;i++){
        if(arr[i] == arr[i-1]&&arr[i-1] == -1){
            cout<<total+4<<'\n';
            return;
        }
    }
    for(int i = 1;i<n;i++){
        if(arr[i] != arr[i-1]){
            cout<<total<<'\n';
            return;
        }
    }
    cout<<total-4<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}