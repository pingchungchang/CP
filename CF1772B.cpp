#include <bits/stdc++.h>
using namespace std;

void turn(int arr[][2]){
    int tmp[2][2];
    tmp[0][0] = arr[1][0];
    tmp[0][1] = arr[0][0];
    tmp[1][0] = arr[1][1];
    tmp[1][1] = arr[0][1];
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++)arr[i][j] = tmp[i][j];
    }
    return;
}
bool check(int arr[][2]){
    if(arr[0][0]>arr[0][1]||arr[1][0]>arr[1][1])return false;
    if(arr[0][0]>arr[1][0]||arr[0][1]>arr[1][1])return false;
    return true;
}
void solve(){
    int arr[2][2];
    for(auto &i:arr)for(auto &j:i)cin>>j;
    for(int i = 0;i<4;i++){
        if(check(arr)){
            cout<<"YES\n";
            return;
        }
        turn(arr);
    }
    cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}