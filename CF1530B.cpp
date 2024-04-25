#include <bits/stdc++.h>
using namespace std;

int arr[33][33];
bool check(int x,int y){
    int dir[] = {-1,0,1};
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(arr[x+dir[i]][y+dir[j]])return false;
        }
    }
    return true;
}
void solve(){
    int n,m;
    cin>>n>>m;
    memset(arr,0,sizeof(arr));
    arr[1][1] = 1;
    for(int i = 2;i<=n;i++){
        if(check(i,1))arr[i][1] = 1;
    }
    for(int i = 1;i<=m;i++)if(check(1,i))arr[1][i] = 1;
    for(int i = 1;i<=m;i++)if(check(n,i))arr[n][i] = 1;
    for(int i = 1;i<=n;i++)if(check(i,m))arr[i][m] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++)cout<<arr[i][j];
        cout<<'\n';
    }
    cout<<'\n';
    return; 
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}