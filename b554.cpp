#include <bits/stdc++.h>
using namespace std;

int arr[8][8] = {};
int dfs(int r,int c){
    if(arr[r][c] == 0)return 0;
    arr[r][c] = 0;
    int big = 0;
    big = max(big,dfs(r,c+1));
    big = max(big,dfs(r+1,c));
    big = max(big,dfs(r-1,c));
    big = max(big,dfs(r,c-1));
    arr[r][c] = 1;
    return big+1;
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++){
        char c;
        cin>>c;
        arr[i][j] = c-'0';
    }
    cout<<dfs(1,1);
}
