#include <bits/stdc++.h>
using namespace std;
struct moves{
    int x;
    int y;
    int z;
    vector<vector<int>> paths;
};
int main(){
    int x,y,z;
    scanf("%d %d %d\n",&x,&y,&z);
    vector<vector<vector<int>>> v(x,vector<vector<int>>(y,vector<int>(z)));
    for(int i =0;i<z;i++){
        for(int j = 0;j<y;j++){
            for(int l = 0;l<x;l++){
                int k;
                scanf("%d",&k);
                v[l][j][i] = k;
            }
        }
    }
    moves start;
    start.x = 0;
    start.y = 0;
    start.z = 0;
    queue<moves> pq;
    pq.push(start);
    vector<vector<int>> ans;
    int done = 0;
    if(v[0][0][0]!=0)done = 1;
    while(!pq.empty()&&done == 0){
        if(v[x-1][y-1][z-1] !=0)break;
        if(ans.size()>0)break;
        moves now = pq.front();
        pq.pop();
        now.paths.push_back({now.x,now.y,now.z});
        // cout<<now.x<<now.y<<now.z<<',' ;
        if(now.x == x-1&&now.y == y-1&&now.z == z-1) ans = now.paths;
        v[now.x][now.y][now.z]= -1;
        if(now.x > 0&&v[now.x-1][now.y][now.z]==0){
            now.x--;
            pq.push(now);
            now.x+=1;
        }
        if(now.x < x-1&&v[now.x+1][now.y][now.z]==0){
            now.x++;
            pq.push(now);
            now.x--;
        }
        if(now.y >0&&v[now.x][now.y-1][now.z]==0){
            now.y--;
            pq.push(now);
            now.y++;
        }
        if(now.y<y-1&&v[now.x][now.y+1][now.z]==0){
            now.y++;
            pq.push(now);
            now.y--;
        }
        if(now.z>0&&v[now.x][now.y][now.z-1]==0){
            now.z--;
            pq.push(now);
            now.z++;
        }
        if(now.z<z-1&&v[now.x][now.y][now.z+1]==0){
            now.z++;
            pq.push(now);
            now.z--;
        }
    }
    if(ans.size()==0)printf("no route");
    else{
        for(int i = 0;i<ans.size();i++){
            printf("(%d,%d,%d)",ans[i][0]+1,ans[i][1]+1,ans[i][2]+1);
            if(i != ans.size()-1)printf("->");
        }
    }
}

//failed