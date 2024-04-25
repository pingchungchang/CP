#include <bits/stdc++.h>
using namespace std;

const int mxn = 707;
int arr[mxn][mxn];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            char c;
            cin>>c;
            if(c != '.')arr[i][j] = c-'0';
        }
    }
    int dx[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(!arr[i][j]){
                int tmp = 0;
                for(auto &d:dx){
                    tmp |= 1<<(arr[i+d[0]][j+d[1]]);
                }
                for(int d = 1;d<=5;d++){
                    if(tmp&(1<<d))continue;
                    arr[i][j] = d;
                    break;
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=m;j++)cout<<arr[i][j];
        cout<<'\n';
    }
    return 0;
}