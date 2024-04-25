#include <bits/stdc++.h>
using namespace std;

int mod =1e4+7;

int main(){
    int n;
    cin>>n;
    n-=1;
    int v[3][3] = {{1,1,1},{1,0,0},{0,1,0}};
    int now[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    while(n>0){
        int ans[3][3];
        if(n&1){
            for(int i =0;i<3;i++){
                for(int j =0;j<3;j++){
                    ans[i][j] = v[i][0]*now[0][j]+v[i][1]*now[1][j]+v[i][2]*now[2][j];
                    ans[i][j]=ans[i][j]%(mod);
                }
            }
            memcpy(now,ans,sizeof(ans));
        }
        for(int i =0;i<3;i++){
            for(int j =0;j<3;j++){
                ans[i][j] = v[i][0]*v[0][j]+v[i][1]*v[1][j]+v[i][2]*v[2][j];
                ans[i][j]=ans[i][j]%(mod);
            }
        }
        memcpy(v,ans,sizeof(ans));
        n>>=1;
    }
    cout<<(now[2][0]+now[2][1]+now[2][2])%(mod);
}