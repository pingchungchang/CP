#include <bits/stdc++.h>
using namespace std;


string arr[303];
int n;
bool eq(vector<int> v){
    int cnt = 0;
    for(int i = 0;i<v.size();i+=2){
        if(arr[v[i]][v[i+1]] == 'X')cnt++;
    }
    return cnt == v.size()/2;
}
void solve(){
    cin>>n;
    for(int i = 0;i<n;i++)cin>>arr[i];  
    for(int i = 1;i<n-1;i++){
        for(int j = 1;j<n-1;j++){
            if(eq({i-1,j,i,j,i+1,j,i,j-1,i,j+1}))arr[i][j] = 'O';
            if(eq({i-1,j-1,i,j-1,i+1,j-1,i,j,i,j+1}))arr[i][j-1] = 'O';
            if(eq({i,j-1,i,j,i,j+1,i-1,j+1,i+1,j+1}))arr[i][j+1] = 'O';
            if(eq({i-1,j-1,i-1,j,i-1,j+1,i,j,i+1,j}))arr[i-1][j] = 'O';
            if(eq({i-1,j,i,j,i+1,j-1,i+1,j,i+1,j+1}))arr[i+1][j] = 'O';
            if(eq({i-1,j-1,i-1,j,i-1,j+1,i,j+1,i+1,j+1}))arr[i-1][j+1] = 'O';
            if(eq({i-1,j-1,i,j-1,i+1,j-1,i-1,j,i-1,j+1}))arr[i-1][j-1] = 'O';
            if(eq({i-1,j-1,i,j-1,i+1,j-1,i+1,j,i+1,j+1}))arr[i+1][j-1] = 'O';
            if(eq({i-1,j+1,i,j+1,i+1,j+1,i+1,j,i+1,j-1}))arr[i+1][j+1] = 'O';
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 1;j<n-1;j++){
            if(arr[i][j] == arr[i][j-1] &&arr[i][j] == arr[i][j+1]&&arr[i][j] == 'X')arr[i][j] = 'O';
        }
    }
    for(int i = 1;i<n-1;i++){
        for(int j= 0;j<n;j++){
            if(arr[i][j] == arr[i-1][j]&&arr[i][j] == arr[i+1][j] &&arr[i][j] == 'X')arr[i][j] = 'O';
        }
    }
    for(int i = 0;i<n;i++)cout<<arr[i]<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}