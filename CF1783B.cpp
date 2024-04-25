#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n][n];
    int l = 1,r = n*n;
    int t = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;i-j>=0;j++){
            if(t&1)arr[j][i-j] = r--;
            else arr[j][i-j] = l++;
        }
        t ^= 1;
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j+i<n;j++){
            if(t&1)arr[i+j][n-1-j] = r--;
            else arr[i+j][n-1-j] = l++;
        }
        t ^= 1;
    }
    for(int i= 0;i<n;i++){
        for(int j= 0;j<n;j++)cout<<arr[i][j]<<' ';
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}