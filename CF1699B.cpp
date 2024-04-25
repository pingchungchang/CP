#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i = 0;i<n;i+=2){
        int pre = ((i>>1)&1);
        for(int j = 0;j<m;j+=2){
            if(pre){
                arr[i][j] = arr[i+1][j+1] = 1;
                arr[i+1][j] = arr[i][j+1] = 0;
            }
            else{
                arr[i][j] = arr[i+1][j+1] = 0;
                arr[i+1][j] = arr[i][j+1] = 1;
            }
            pre ^= 1;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++)cout<<arr[i][j]<<' ';cout<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}