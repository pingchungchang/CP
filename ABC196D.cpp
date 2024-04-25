#include <bits/stdc++.h>
using namespace std;

int arr[17][17] = {};
int h,w;
int ans = 0;
void dfs(int r,int c,int a,int b){
    if(r == h-1&&c == w-1){
        ans++;
        return;
    }
    if(arr[r][c] != 0){
        if(c == w-1)dfs(r+1,0,a,b);
        else dfs(r,c+1,a,b);
        return;
    }
    if(b != 0&&c != w-1&&arr[r][c+1] == 0){
        arr[r][c] = 1;
        arr[r][c+1] = 1;
        dfs(r,c+1,a,b-1);
        arr[r][c] = 0;
        arr[r][c+1] = 0;
    }
    if(b != 0&&r != h-1){
        arr[r][c] = 1;
        arr[r+1][c] = 1;
        if(c != w-1)dfs(r,c+1,a,b-1);
        else dfs(r,0,a,b-1);
        arr[r][c] = 0;
        arr[r+1][c] = 0;
    }
    if(a != 0){
        arr[r][c] = 1;
        if(c != w-1)dfs(r,c+1,a-1,b);
        else dfs(r,0,a-1,b);
        arr[r][c] = 0;
    }
    return;
}
int main(){
    int a,b;
    cin>>h>>w>>a>>b;
    dfs(0,0,b,a);
    cout<<ans;
}
