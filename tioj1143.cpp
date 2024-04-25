#include <bits/stdc++.h>
using namespace std;

const int mxn = 101;
int arr[mxn][mxn];
#define pii pair<int,int>
#define fs first
#define sc second
int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        arr[a][b] = -1;
    }
    queue<pii> q;
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    q.push({sx,sy});
    arr[sx][sy] = 1;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(now.fs+3<=99&&now.sc+1<=99&&arr[now.fs+1][now.sc] != -1&&!arr[now.fs+3][now.sc+1]){
            arr[now.fs+3][now.sc+1] = arr[now.fs][now.sc]+1;
            q.push({now.fs+3,now.sc+1});
        }
        if(now.fs+3<=99&&now.sc-1>=0&&arr[now.fs+1][now.sc] != -1&&!arr[now.fs+3][now.sc-1]){
            arr[now.fs+3][now.sc-1] = arr[now.fs][now.sc]+1;
            q.push({now.fs+3,now.sc-1});
        }
        if(now.fs-3>=0&&now.fs+1<=99&&arr[now.fs-1][now.sc] != -1&&!arr[now.fs-3][now.sc+1]){
            arr[now.fs-3][now.sc+1] = arr[now.fs][now.sc]+1;
            q.push({now.fs-3,now.sc+1});
        }
        if(now.fs-3>=0&&now.sc-1>=0&&arr[now.fs-1][now.sc] != -1&&!arr[now.fs-3][now.sc-1]){
            arr[now.fs-3][now.sc-1] = arr[now.fs][now.sc]+1;
            q.push({now.fs-3,now.sc-1});
        }
        if(now.fs-1>=0&&now.sc+3<=99&&arr[now.fs][now.sc+1] != -1&&!arr[now.fs-1][now.sc+3]){
            arr[now.fs-1][now.sc+3] = arr[now.fs][now.sc]+1;
            q.push({now.fs-1,now.sc+3});
        }
        if(now.fs-1>=0&&now.sc-3>=0&&arr[now.fs][now.sc-1] != -1&&!arr[now.fs-1][now.sc-3]){
            arr[now.fs-1][now.sc-3] = arr[now.fs][now.sc]+1;
            q.push({now.fs-1,now.sc-3});
        }
        if(now.fs+1<=99&&now.sc+3<=99&&arr[now.fs][now.sc+1] != -1&&!arr[now.fs+1][now.sc+3]){
            arr[now.fs+1][now.sc+3] = arr[now.fs][now.sc]+1;
            q.push({now.fs+1,now.sc+3});
        }
        if(now.fs+1<=99&&now.sc-3>=0&&arr[now.fs][now.sc-1] != -1&&!arr[now.fs+1][now.sc-3]){
            arr[now.fs+1][now.sc-3] = arr[now.fs][now.sc]+1;
            q.push({now.fs+1,now.sc-3});
        }
    }
    if(arr[ex][ey] == 0)cout<<"impossible";
    else cout<<arr[ex][ey]-1;
}